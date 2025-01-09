#pragma once
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
