#pragma once
#include <cmath>
#include <functional>

#ifndef SYGNAL_H
#define SYGNAL_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Sygnal {
private:
    double amplituda;
    double okres;
    double wypelnienie;
    double czas_aktywacji;
    std::function<double(double)> funkcja_sygnalu;

public:

    Sygnal(double amplituda = 1.0, double okres = 1.0, double wypelnienie = 0.5, double czas_aktywacji = 0.0);

    void ustawSkok();

    void ustawSinus();

    void ustawProstokat();

    double generuj(double t) const;
};

#endif 
