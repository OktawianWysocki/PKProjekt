#include "PID.h"
#include "Arx.h"
#include "Sprzezenie.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

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
