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
