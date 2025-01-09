#include "PID.h"
#include "Arx.h"
#include"Sygnal.h"
#include "Sprzezenie.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>


// Implementacja klasy Sygnal
Sygnal::Sygnal(double amplituda, double okres, double wypelnienie, double czas_aktywacji)
    : amplituda(amplituda), okres(okres), wypelnienie(wypelnienie), czas_aktywacji(czas_aktywacji) {
    ustawSkok(); // Domyślnie ustawiony skok jednostkowy
}

void Sygnal::ustawSkok() {
    funkcja_sygnalu = [this](double t) {
        return t >= czas_aktywacji ? amplituda : 0.0;
        };
}

void Sygnal::ustawSinus() {
    funkcja_sygnalu = [this](double t) {
        return amplituda * std::sin((2.0 * M_PI / okres) * t);
        };
}

void Sygnal::ustawProstokat() {
    funkcja_sygnalu = [this](double t) {
        double modulo = std::fmod(t, okres);
        return (modulo / okres) < wypelnienie ? amplituda : 0.0;
        };
}

double Sygnal::generuj(double t) const {
    if (funkcja_sygnalu) {
        return funkcja_sygnalu(t);
    }
    return 0.0; // Domyślnie zwraca 0, jeśli brak przypisanej funkcji sygnału
}
