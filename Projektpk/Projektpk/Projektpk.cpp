#include <iostream>
#include "KLASY.H"

int main() {
    // Współczynniki modelu ARX
    std::vector<double> wspolczynniki_a = { -0.4 }; // Współczynniki A
    std::vector<double> wspolczynniki_b = { 0.6 };  // Współczynniki B
    int opoznienie_k = 1; // Opóźnienie transportowe

    // Inicjalizacja modelu ARX
    Arx model(wspolczynniki_a, wspolczynniki_b, opoznienie_k);

    // Sygnał wejściowy (skok jednostkowy)
    std::vector<double> sygnal_wejscia = { 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.5, 0.5, 0.5 };

    // Symulacja
    for (size_t i = 0; i < sygnal_wejscia.size(); ++i) {
        double y = model.wykonaj_krok(sygnal_wejscia[i]);
        std::cout << "Krok " << i << ": u = " << sygnal_wejscia[i] << ", y = " << y << std::endl;
    }

    return 0;
}
