#include "PID.h"
#include"Symulacja.h"
#include "Arx.h"
#include"Sygnal.h"
#include "Sprzezenie.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>


int main() {

    Arx model({ -0.4 }, { 0.6 }, 1);
    PID regulator(2.0, 1.0, 0.5);
    Sprzerzenie sprzerzenie(&model, &regulator, 1.0);

    Sygnal sygnal(1.0, 10.0);
    sygnal.ustawSinus();

    Symulacja symulacja(&sprzerzenie, &sygnal, 0.1);

    symulacja.start();

    double czas = 0.0;
    for (int i = 0; i < 100; ++i) {
        double wynik = symulacja.symulujKrok(czas);
        std::cout << "Czas: " << czas << " s, Wyjscie: " << wynik << std::endl;
        czas += 0.1;
    }

    symulacja.stop();
    return 0;
}
