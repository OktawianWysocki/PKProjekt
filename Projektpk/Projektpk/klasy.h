#include <vector>
#include <cmath>
#include <functional>

#ifndef ARX_H
#define ARX_H

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


#ifndef PID_H
#define PID_H

class PID {
private:
    double kp;               // Wzmocnienie proporcjonalne
    double ti;               // Stała całkowania
    double td;               // Stała różniczkowania
    double suma_uchybow;     // Suma uchybów do obliczeń składowej całkującej
    double poprzedni_uchyb;  // Ostatnia wartość uchybu (do różniczkowania)

public:
    
    PID(double kp, double ti, double td);

    
    double obliczP(double uchyb) const;        // Składowa proporcjonalna
    double obliczI(double uchyb);              // Składowa całkująca
    double obliczD(double uchyb);              // Składowa różniczkująca

    // Funkcja obliczająca całkowitą wartość sterowania
    double obliczSterowanie(double uchyb);

    // Resetowanie stanu kontrolera
    void reset();
};

#endif 

#ifndef SPRZERZENIE_H
#define SPRZERZENIE_H


class Sprzerzenie {
private:
    Arx* m_model;      // Obiekt regulacji (model ARX)
    PID* m_pid;        // Regulator PID
    double wartosc_zadana; // Wartość zadana w(i)
    double poprzednie_y;   // Wartość zmierzona (𝑦𝑖 = 𝑦𝑖−1)

public:
    
    Sprzerzenie(Arx* model, PID* pid, double wartosc_zadana);

    // Oblicza uchyb regulacji
    double obliczUchyb(double aktualne_y);

    // Wykonuje krok symulacji
    double wykonajKrok(double aktualne_y);
};

#endif 

#ifndef SYGNAL_H
#define SYGNAL_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Sygnal {
private:
    double amplituda;    // Amplituda sygnału
    double okres;        // Okres sygnału (dla sinusa i prostokąta)
    double wypelnienie;  // Wypełnienie sygnału prostokątnego (0 - 1)
    double czas_aktywacji; // Moment aktywacji skoku jednostkowego
    std::function<double(double)> funkcja_sygnalu; // Wybrana funkcja generująca sygnał

public:
    
    Sygnal(double amplituda = 1.0, double okres = 1.0, double wypelnienie = 0.5, double czas_aktywacji = 0.0);

    // Ustawienie sygnału jako skok jednostkowy
    void ustawSkok();

    // Ustawienie sygnału sinusoidalnego
    void ustawSinus();

    // Ustawienie sygnału prostokątnego
    void ustawProstokat();

    // Generowanie wartości sygnału w danym momencie czasowym
    double generuj(double t) const;
};

#endif 

#ifndef SYMULACJA_H
#define SYMULACJA_H

class Symulacja {
private:
    Sprzerzenie* sprzerzenie; // Obiekt sprzężenia zwrotnego
    Sygnal* sygnal;           // Obiekt sygnału wartości zadanej
    double krok_czasowy;      // Krok czasowy symulacji
    bool aktywna;             // Flaga aktywności symulacji

public:
    
    Symulacja(Sprzerzenie* sprzerzenie, Sygnal* sygnal, double krok_czasowy = 0.1);

    // Rozpoczęcie symulacji
    void start();

    // Zatrzymanie symulacji
    void stop();

    // Reset symulacji
    void reset();

    // Wykonanie kroku symulacji
    double symulujKrok(double czas);

    // Ustawienie nowego kroku czasowego
    void ustawKrokCzasowy(double nowy_krok);
};

#endif 
