#ifndef ARX_H
#define ARX_H

#include <vector>

class Arx {
private:
    std::vector<double> wspolczynniki_a; // Współczynniki wektora A
    std::vector<double> wspolczynniki_b; // Współczynniki wektora B
    int opoznienie_k; // Opóźnienie transportowe
    std::vector<double> bufor_wejscia;  // Bufor sygnału wejściowego (u)
    std::vector<double> bufor_wyjscia; // Bufor sygnału wyjściowego (y)

public:
    // Konstruktor klasy ARX
    Arx(const std::vector<double>& a, const std::vector<double>& b, int k);

    // Metoda wykonująca pojedynczy krok symulacji
    double wykonaj_krok(double u);
};

#endif // ARX_H


#ifndef PID_H
#define PID_H

class PID {
private:
    double kp;               // Wzmocnienie proporcjonalne
    double ti;               // Stała całkowania
    double td;               // Stała różniczkowania
    double suma_uchybow;     // Suma uchybów do obliczeń składowej całkującej
    double poprzedni_uchyb;  // Ostatnia wartość uchybu (do różniczkowania)

public:
    // Konstruktor
    PID(double kp, double ti, double td);

    // Funkcje obliczające poszczególne składowe
    double obliczP(double uchyb) const;        // Składowa proporcjonalna
    double obliczI(double uchyb);              // Składowa całkująca
    double obliczD(double uchyb);              // Składowa różniczkująca

    // Funkcja obliczająca całkowitą wartość sterowania
    double obliczSterowanie(double uchyb);

    // Resetowanie stanu kontrolera
    void reset();
};

#endif // PID_H

#ifndef SPRZERZENIE_H
#define SPRZERZENIE_H


class Sprzerzenie {
private:
    Arx* m_model;      // Obiekt regulacji (model ARX)
    PID* m_pid;        // Regulator PID
    double wartosc_zadana; // Wartość zadana w(i)
    double poprzednie_y;   // Wartość zmierzona (𝑦̂𝑖 = 𝑦𝑖−1)

public:
    // Konstruktor
    Sprzerzenie(Arx* model, PID* pid, double wartosc_zadana);

    // Oblicza uchyb regulacji
    double obliczUchyb(double aktualne_y);

    // Wykonuje krok symulacji
    double wykonajKrok(double aktualne_y);
};

#endif // SPRZERZENIE_H

#ifndef SYGNAL_H
#define SYGNAL_H

#include <cmath>
#include <functional>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Sygnal {
private:
    double amplituda;    // Amplituda sygnału
    double okres;        // Okres sygnału (dla sinusa i prostokąta)
    double wypełnienie;  // Wypełnienie sygnału prostokątnego (0 - 1)
    double czas_aktywacji; // Moment aktywacji skoku jednostkowego
    std::function<double(double)> funkcja_sygnalu; // Wybrana funkcja generująca sygnał

public:
    // Konstruktor
    Sygnal(double amplituda = 1.0, double okres = 1.0, double wypełnienie = 0.5, double czas_aktywacji = 0.0);

    // Ustawienie sygnału jako skok jednostkowy
    void ustawSkok();

    // Ustawienie sygnału sinusoidalnego
    void ustawSinus();

    // Ustawienie sygnału prostokątnego
    void ustawProstokat();

    // Generowanie wartości sygnału w danym momencie czasowym
    double generuj(double t) const;
};

#endif // SYGNAL_H

#ifndef SYMULACJA_H
#define SYMULACJA_H

class Symulacja {
private:
    Sprzerzenie* sprzerzenie; // Obiekt sprzężenia zwrotnego
    Sygnal* sygnal;           // Obiekt sygnału wartości zadanej
    double krok_czasowy;      // Krok czasowy symulacji
    bool aktywna;             // Flaga aktywności symulacji

public:
    // Konstruktor
    Symulacja(Sprzerzenie* sprzerzenie, Sygnal* sygnal, double krok_czasowy = 0.1);

    // Rozpoczęcie symulacji
    void start();

    // Zatrzymanie symulacji
    void stop();

    // Reset symulacji
    void reset();

    // Wykonanie kroku symulacji
    double symulujKrok(double czas);

    // Ustawienie nowego kroku czasowego
    void ustawKrokCzasowy(double nowy_krok);
};

#endif // SYMULACJA_H