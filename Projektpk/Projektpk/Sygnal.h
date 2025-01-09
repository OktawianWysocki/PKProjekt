#pragma once
#ifndef SYGNAL_H
#define SYGNAL_H
#include "PID.h"
#include "Arx.h"
#include "Sprzezenie.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Sygnal {
private:
    double amplituda;    // Amplituda sygnału
    double okres;        // Okres sygnału (dla sinusa i prostokąta)
    double wypelnienie;  // Wypełnienie sygnału prostokątnego (0 - 1)
    double czas_aktywacji; // Moment aktywacji skoku jednostkowego
    std::function<double(double)> funkcja_sygnalu; // Wybrana funkcja generująca sygnał

public:

    Sygnal(double amplituda = 1.0, double okres = 1.0, double wypelnienie = 0.5, double czas_aktywacji = 0.0);

    // Ustawienie sygnału jako skok jednostkowy
    void ustawSkok();

    // Ustawienie sygnału sinusoidalnego
    void ustawSinus();

    // Ustawienie sygnału prostokątnego
    void ustawProstokat();

    // Generowanie wartości sygnału w danym momencie czasowym
    double generuj(double t) const;
};

#endif 
