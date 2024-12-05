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
    // Konstruktor klasy ARX
    Arx(const std::vector<double>& a, const std::vector<double>& b, int k);

    // Metoda wykonująca pojedynczy krok symulacji
    double wykonaj_krok(double u);
};

#endif // ARX_H

class Sprzerzenie
{
    Arx* m_model;
    Pid* m_pid;
    Sygnal* m_sygnal;
public:
    double uchyb();
    double wynikSprzerzenia();

};
class Pid
{
    double kp;
    double ti;
    double td;
    double poprzedniUchyb;
public:
    double algortmI();
    double algortmP();
    double algortmD();
    double sumaAlgorytmow();
    void reset();
};
class Sygnal {};
