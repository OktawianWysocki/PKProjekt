#pragma once
#ifndef SYMULACJA_H
#define SYMULACJA_H
#include "PID.h"
#include "Arx.h"
#include"Sygnal.h"
#include "Sprzezenie.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

class Symulacja {
private:
    Sprzerzenie* sprzerzenie; // Obiekt sprzężenia zwrotnego
    Sygnal* sygnal;           // Obiekt sygnału wartości zadanej
    double krok_czasowy;      // Krok czasowy symulacji
    bool aktywna;             // Flaga aktywności symulacji

public:

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

#endif 
