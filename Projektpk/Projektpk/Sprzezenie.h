#pragma once
#include "PID.h"
#include "Arx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

#ifndef SPRZERZENIE_H
#define SPRZERZENIE_H


class Sprzerzenie {
private:
    Arx* m_model;      // Obiekt regulacji (model ARX)
    PID* m_pid;        // Regulator PID
    double wartosc_zadana; // Wartość zadana w(i)
    double poprzednie_y;   // Wartość zmierzona (𝑦𝑖 = 𝑦𝑖−1)

public:

    Sprzerzenie(Arx* model, PID* pid, double wartosc_zadana);

    // Oblicza uchyb regulacji
    double obliczUchyb(double aktualne_y);

    // Wykonuje krok symulacji
    double wykonajKrok(double aktualne_y);
};

#endif 
