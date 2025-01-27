#include "Arx.h"

Arx::Arx(const std::vector<double>& wsp_b, const std::vector<double>& wsp_a, int opoznienie)
    : b(wsp_b), a(wsp_a), delay(opoznienie), wejscia(wsp_b.size(), 0.0), wyjscia(wsp_a.size(), 0.0) {}

void Arx::aktualizuj(double wejscie) {
    wejscia.insert(wejscia.begin(), wejscie);
    wejscia.pop_back();
    wyjscia.insert(wyjscia.begin(), wyliczWyjscie(0.0));
    wyjscia.pop_back();
}

double Arx::wyliczWyjscie(double sterowanie) {
    double wyjscie = 0.0;
    for (size_t i = 0; i < b.size(); ++i) {
        wyjscie += b[i] * (i < wejscia.size() ? wejscia[i] : 0.0);
    }
    for (size_t i = 1; i < a.size(); ++i) {
        wyjscie -= a[i] * (i < wyjscia.size() ? wyjscia[i] : 0.0);
    }
    return wyjscie + sterowanie;
}
