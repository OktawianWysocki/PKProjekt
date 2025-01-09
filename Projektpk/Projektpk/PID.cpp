#include "PID.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

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
