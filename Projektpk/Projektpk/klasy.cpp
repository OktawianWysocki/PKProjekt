#include"KLASY.H"
#include<iostream>



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

double Sprzerzenie::uchyb() {

}

double Sprzerzenie::wynikSprzerzenia() {

}



double Pid::algortmI() {

}

double Pid::algortmP() {

}

double Pid::algortmD() {

}

double Pid::sumaAlgorytmow() {

}

void Pid::reset() {

}






