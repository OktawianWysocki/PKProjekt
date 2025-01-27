#pragma once
#include "Sprzezenie.h"
#include "Sygnal.h"

#ifndef SYMULACJA_H
#define SYMULACJA_H

class Symulacja {
private:
    Sprzezenie* sprzezenie;
    Sygnal* sygnal;
    double krok_czasowy;
    bool aktywna;

public:
    Symulacja(Sprzezenie* sprzezenie, Sygnal* sygnal, double krok_czasowy = 0.1);

    void start();
    void stop();
    void reset();
    double symulujKrok(double czas);
};

#endif
