#pragma once
#include "Arx.h"
#include "PID.h"
#include <cmath>

#ifndef SPRZEZENIE_H
#define SPRZEZENIE_H

enum SygnalTyp {
    SKOK_JEDNOSTKOWY,
    SINUSOIDA,
    PROSTOKATNY
};

class Sprzezenie {
private:
    Arx* model;
    PID* regulator;
    double wzmocnienie;

    SygnalTyp sygnalTyp;
    double amplituda;
    double okres;
    double offset;

public:
    Sprzezenie(Arx* model, PID* regulator, double wzmocnienie);

    double wykonajKrok(double uchyb);
    void aktualizuj(double uchyb, double sterowanie);
    void ustawSygnal(SygnalTyp typ, double amplituda, double okres, double offset = 0.0);
    double generujSygnal(double czas);

    void reset(); // Nowa metoda resetująca
};

#endif
