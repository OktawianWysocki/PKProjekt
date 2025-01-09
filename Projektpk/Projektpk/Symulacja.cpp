#include "PID.h"
#include"Symulacja.h"
#include "Arx.h"
#include"Sygnal.h"
#include "Sprzezenie.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>


// Implementacja klasy Symulacja
Symulacja::Symulacja(Sprzerzenie* sprzerzenie, Sygnal* sygnal, double krok_czasowy)
    : sprzerzenie(sprzerzenie), sygnal(sygnal), krok_czasowy(krok_czasowy), aktywna(false) {}

void Symulacja::start() {
    aktywna = true;
    std::cout << "Symulacja rozpoczeta.\n";
}

void Symulacja::stop() {
    aktywna = false;
    std::cout << "Symulacja zatrzymana.\n";
}

void Symulacja::reset() {
    aktywna = false;
    std::cout << "Symulacja zresetowana.\n";
}

double Symulacja::symulujKrok(double czas) {
    if (!aktywna) {
        std::cerr << "Symulacja nie jest aktywna!\n";
        return 0.0;
    }
    if (!sygnal || !sprzerzenie) {
        std::cerr << "Blad: Brak sygnalu lub sprzezenia zwrotnego!\n";
        return 0.0;
    }
    double wartosc_zadana = sygnal->generuj(czas);
    double wynik = sprzerzenie->wykonajKrok(wartosc_zadana);
    return wynik;
}

void Symulacja::ustawKrokCzasowy(double nowy_krok) {
    krok_czasowy = nowy_krok;
    std::cout << "Nowy krok czasowy: " << krok_czasowy << "\n";
}
