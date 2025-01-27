#include "Symulacja.h"
#include <iostream>

Symulacja::Symulacja(Sprzezenie* sprzezenie, Sygnal* sygnal, double krok_czasowy)
    : sprzezenie(sprzezenie), sygnal(sygnal), krok_czasowy(krok_czasowy), aktywna(false) {}

void Symulacja::start() {
    aktywna = true;
    std::cout << "Symulacja rozpoczęta." << std::endl;
}

void Symulacja::stop() {
    aktywna = false;
    std::cout << "Symulacja zatrzymana." << std::endl;
}

void Symulacja::reset() {
    aktywna = false;
    std::cout << "Symulacja zresetowana." << std::endl;
}

double Symulacja::symulujKrok(double czas) {
    if (!aktywna) {
        std::cerr << "Symulacja nie jest aktywna!" << std::endl;
        return 0.0;
    }
    double wartosc_zadana = sygnal->generuj(czas);
    double wynik = sprzezenie->wykonajKrok(wartosc_zadana);
    return wynik;
}
