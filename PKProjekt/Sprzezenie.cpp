#include "Sprzezenie.h"
#include "PID.h"
#include "Arx.h"
#include <cmath>
#include <QDebug> // Dodano do logowania informacji

Sprzezenie::Sprzezenie(Arx* model, PID* regulator, double wzmocnienie)
    : model(model), regulator(regulator), wzmocnienie(wzmocnienie),
    sygnalTyp(SKOK_JEDNOSTKOWY), amplituda(1.0), okres(1.0), offset(0.0) {}

double Sprzezenie::wykonajKrok(double uchyb) {
    double sterowanie = regulator->obliczSterowanie(uchyb, 0.1);
    return model->wyliczWyjscie(sterowanie);
}

void Sprzezenie::aktualizuj(double uchyb, double sterowanie) {
    model->aktualizuj(sterowanie);
}

void Sprzezenie::ustawSygnal(SygnalTyp typ, double amplituda, double okres, double offset) {
    this->sygnalTyp = typ;
    this->amplituda = amplituda;
    this->okres = okres;
    this->offset = offset;
}

double Sprzezenie::generujSygnal(double czas) {
    switch (sygnalTyp) {
    case SKOK_JEDNOSTKOWY:
        return (czas >= offset) ? amplituda : 0.0;
    case SINUSOIDA:
        return amplituda * sin((2 * M_PI * czas) / okres) + offset;
    case PROSTOKATNY:
        return (fmod(czas, okres) < okres / 2) ? amplituda + offset : -amplituda + offset;
    default:
        return 0.0;
    }
}

// Nowa metoda resetująca stan sprzężenia
void Sprzezenie::reset() {
    model->aktualizuj(0.0); // Resetowanie modelu (przykładowa logika)
    regulator->reset();     // Resetowanie regulatora PID
    qDebug() << "Sprzezenie reset to initial state.";
}
