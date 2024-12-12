#include <iostream>
#include "KLASY.H"

int main() {
    // Tworzenie obiektu ARX z przykładowymi współczynnikami
    Arx model({ -0.4 }, { 0.6 }, 1);

    // Tworzenie regulatora PID
    PID regulator(2.0, 1.0, 0.5);

    // Tworzenie obiektu sprzężenia zwrotnego
    Sprzerzenie sprzerzenie(&model, &regulator, 1.0); // Wartość zadana = 1.0

    // Tworzenie sygnału
    Sygnal sygnal(1.0, 10.0); // Amplituda 1.0, okres 10.0
    sygnal.ustawSinus();      // Ustawiamy sygnał jako sinusoidalny

    // Tworzenie obiektu symulacji
    Symulacja symulacja(&sprzerzenie, &sygnal, 0.1); // Krok czasowy 0.1 sekundy

    // Rozpoczynamy symulację
    symulacja.start();

    double czas = 0.0;
    for (int i = 0; i < 100; ++i) { // 100 kroków symulacji
        double wynik = symulacja.symulujKrok(czas);
        std::cout << "Czas: " << czas << " s, Wyjscie: " << wynik << std::endl;
        czas += 0.1; // Krok czasowy
    }

    symulacja.stop();
    return 0;
}