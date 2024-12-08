#include <iostream>
#include "KLASY.H"

int main() {
    // Tworzenie obiektu ARX z przykładowymi współczynnikami
    Arx model({ -0.4 }, { 0.6 }, 1);

    // Tworzenie regulatora PID
    PID regulator(2.0, 1.0, 0.5);

    // Tworzenie obiektu sprzężenia zwrotnego
    Sprzerzenie sprzerzenie(&model, &regulator, 1.0); // Wartość zadana = 1.0

    // Symulacja
    double y = 0.0; // Początkowa wartość wyjścia
    for (int i = 0; i < 10; ++i) {
        y = sprzerzenie.wykonajKrok(y); // Wykonanie kroku symulacji
        std::cout << "Krok " << i << ": y = " << y << std::endl;
    }

    return 0;
}
