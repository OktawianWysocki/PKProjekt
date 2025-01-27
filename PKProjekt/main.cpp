#include "gui.h"
#include "PID.h"
#include "Symulacja.h"
#include "Arx.h"
#include "Sygnal.h"
#include "Sprzezenie.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <cmath>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    gui w;

    QObject::connect(&w, &gui::startSimulation, [&]() {
        Arx model({-0.4}, {0.6}, 1);
        PID regulator(2.0, 1.0, 0.5);
        Sprzezenie sprzezenie(&model, &regulator, 1.0);

        Sygnal sygnal(1.0, 10.0);
        sygnal.ustawSinus();

        Symulacja symulacja(&sprzezenie, &sygnal, 0.1);
        symulacja.start();

        double czas = 0.0;
        for (int i = 0; i < 100; ++i) {
            double wynik = symulacja.symulujKrok(czas);
            std::cout << "Czas: " << czas << " s, Wyjscie: " << wynik << std::endl;
            czas += 0.1;
        }

        symulacja.stop();
    });

    w.show();
    return app.exec();
}
