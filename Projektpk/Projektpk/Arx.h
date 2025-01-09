#pragma once
#ifndef ARX_H
#define ARX_H

#include <vector>

class Arx {
private:
    std::vector<double> wspolczynniki_a; // Współczynniki wektora A
    std::vector<double> wspolczynniki_b; // Współczynniki wektora B
    int opoznienie_k; // Opóźnienie transportowe
    std::vector<double> bufor_wejscia;  // Bufor sygnału wejściowego (u)
    std::vector<double> bufor_wyjscia; // Bufor sygnału wyjściowego (y)

public:

    Arx(const std::vector<double>& a, const std::vector<double>& b, int k);

    // Metoda wykonująca pojedynczy krok symulacji
    double wykonaj_krok(double u);
};
#endif
