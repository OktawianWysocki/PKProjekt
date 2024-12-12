#include "KLASY.H"
#include <iostream>



Arx::Arx(const std::vector<double>& a, const std::vector<double>& b, int k)
    : wspolczynniki_a(a), wspolczynniki_b(b), opoznienie_k(k) {
    // Inicjalizacja buforów zerami
    bufor_wejscia.resize(b.size() + k, 0.0); // Bufor wejściowy musi uwzględniać opóźnienie
    bufor_wyjscia.resize(a.size(), 0.0);    // Bufor wyjściowy odpowiada długości współczynników A
}

double Arx::wykonaj_krok(double u) {
    // Aktualizacja bufora wejściowego
    for (size_t i = bufor_wejscia.size() - 1; i > 0; --i) {
        bufor_wejscia[i] = bufor_wejscia[i - 1]; // Przesuwanie wartości w prawo
    }
    bufor_wejscia[0] = u; // Dodanie nowej wartości wejściowej

    // Obliczenie składowej sygnału wejściowego
    double skladnik_wejscia = 0.0;
    for (size_t i = 0; i < wspolczynniki_b.size(); ++i) {
        skladnik_wejscia += wspolczynniki_b[i] * bufor_wejscia[i + opoznienie_k];
    }

    // Obliczenie składowej sygnału wyjściowego
    double skladnik_wyjscia = 0.0;
    for (size_t i = 0; i < wspolczynniki_a.size(); ++i) {
        skladnik_wyjscia += wspolczynniki_a[i] * bufor_wyjscia[i];
    }

    // Wyliczenie nowego sygnału wyjściowego
    double y = skladnik_wejscia - skladnik_wyjscia;

    // Aktualizacja bufora wyjściowego
    for (size_t i = bufor_wyjscia.size() - 1; i > 0; --i) {
        bufor_wyjscia[i] = bufor_wyjscia[i - 1]; // Przesuwanie wartości w prawo
    }
    bufor_wyjscia[0] = y; // Dodanie nowej wartości wyjściowej

    return y;
}

PID::PID(double kp, double ti, double td)
    : kp(kp), ti(ti), td(td), suma_uchybow(0.0), poprzedni_uchyb(0.0) {}

// Składowa proporcjonalna
double PID::obliczP(double uchyb) const {
    return kp * uchyb;
}

// Składowa całkująca
double PID::obliczI(double uchyb) {
    if (ti == 0.0) {
        return 0.0; // Część całkująca wyłączona
    }
    suma_uchybow += uchyb; // Aktualizacja sumy uchybów
    return (1.0 / ti) * suma_uchybow;
}

// Składowa różniczkująca
double PID::obliczD(double uchyb) {
    double wynik = td * (uchyb - poprzedni_uchyb); // Przyrost uchybu
    poprzedni_uchyb = uchyb; // Aktualizacja pamięci uchybu
    return wynik;
}

// Całkowita wartość sterowania
double PID::obliczSterowanie(double uchyb) {
    double uP = obliczP(uchyb); // Składowa P
    double uI = obliczI(uchyb); // Składowa I
    double uD = obliczD(uchyb); // Składowa D
    return uP + uI + uD;        // Suma wszystkich składowych
}

// Resetowanie stanu kontrolera
void PID::reset() {
    suma_uchybow = 0.0;
    poprzedni_uchyb = 0.0;
} 

Sprzerzenie::Sprzerzenie(Arx* model, PID* pid, double wartosc_zadana)
    : m_model(model), m_pid(pid), wartosc_zadana(wartosc_zadana), poprzednie_y(0.0) {}

// Oblicza uchyb regulacji
double Sprzerzenie::obliczUchyb(double aktualne_y) {
    poprzednie_y = aktualne_y; // Aktualizacja poprzedniego y
    return wartosc_zadana - poprzednie_y; // e(i) = w(i) - y_hat(i)
}

// Wykonuje krok symulacji
double Sprzerzenie::wykonajKrok(double aktualne_y) {
    // Oblicz uchyb
    double uchyb = obliczUchyb(aktualne_y);

    // Oblicz sterowanie PID
    double sterowanie = m_pid->obliczSterowanie(uchyb);

    // Przekaż sterowanie do modelu ARX i uzyskaj nowe y
    double nowe_y = m_model->wykonaj_krok(sterowanie);

    return nowe_y; // Zwraca nową wartość regulowaną
}

// Implementacja klasy Sygnal
Sygnal::Sygnal(double amplituda, double okres, double wypelnienie, double czas_aktywacji)
    : amplituda(amplituda), okres(okres), wypelnienie(wypelnienie), czas_aktywacji(czas_aktywacji) {
    ustawSkok(); // Domyślnie ustawiony skok jednostkowy
}

void Sygnal::ustawSkok() {
    funkcja_sygnalu = [this](double t) {
        return t >= czas_aktywacji ? amplituda : 0.0;
        };
}

void Sygnal::ustawSinus() {
    funkcja_sygnalu = [this](double t) {
        return amplituda * std::sin((2.0 * M_PI / okres) * t);
        };
}

void Sygnal::ustawProstokat() {
    funkcja_sygnalu = [this](double t) {
        double modulo = std::fmod(t, okres);
        return (modulo / okres) < wypelnienie ? amplituda : 0.0;
        };
}

double Sygnal::generuj(double t) const {
    if (funkcja_sygnalu) {
        return funkcja_sygnalu(t);
    }
    return 0.0; // Domyślnie zwraca 0, jeśli brak przypisanej funkcji sygnału
}

// Implementacja klasy Symulacja
Symulacja::Symulacja(Sprzerzenie* sprzerzenie, Sygnal* sygnal, double krok_czasowy)
    : sprzerzenie(sprzerzenie), sygnal(sygnal), krok_czasowy(krok_czasowy), aktywna(false) {}

void Symulacja::start() {
    aktywna = true;
    std::cout << "Symulacja rozpoczeta.\n";
}

void Symulacja::stop() {
    aktywna = false;
    std::cout << "Symulacja zatrzymana.\n";
}

void Symulacja::reset() {
    aktywna = false;
    std::cout << "Symulacja zresetowana.\n";
}

double Symulacja::symulujKrok(double czas) {
    if (!aktywna) {
        std::cerr << "Symulacja nie jest aktywna!\n";
        return 0.0;
    }
    if (!sygnal || !sprzerzenie) {
        std::cerr << "Blad: Brak sygnalu lub sprzezenia zwrotnego!\n";
        return 0.0;
    }
    double wartosc_zadana = sygnal->generuj(czas);
    double wynik = sprzerzenie->wykonajKrok(wartosc_zadana);
    return wynik;
}

void Symulacja::ustawKrokCzasowy(double nowy_krok) {
    krok_czasowy = nowy_krok;
    std::cout << "Nowy krok czasowy: " << krok_czasowy << "\n";
}