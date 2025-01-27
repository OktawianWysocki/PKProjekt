#pragma once
#include <vector>

#ifndef ARX_H
#define ARX_H

class Arx {
private:
    std::vector<double> b, a;
    int delay;
    std::vector<double> wejscia, wyjscia;

public:
    Arx(const std::vector<double>& wsp_b, const std::vector<double>& wsp_a, int opoznienie);
    void aktualizuj(double wejscie);
    double wyliczWyjscie(double sterowanie);
};

#endif
