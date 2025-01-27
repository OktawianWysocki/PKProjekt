#include "PID.h"
#include <cmath>

PID::PID(double Kp, double Ti, double Td)
    : Kp(Kp), Ti(Ti), Td(Td), SumaUchybów(0.0), PoprzedniUchyb(0.0), OstatnieSterowanie(0.0) {}

double PID::obliczSterowanie(double uchyb, double deltaT) {
    double P = Kp * uchyb;
    SumaUchybów += uchyb * deltaT;
    double I = (Ti != 0.0) ? (Kp / Ti) * SumaUchybów : 0.0;
    double D = (Td != 0.0) ? Td * Kp * (uchyb - PoprzedniUchyb) / deltaT : 0.0;

    PoprzedniUchyb = uchyb;
    OstatnieSterowanie = P + I + D;
    return OstatnieSterowanie;
}

void PID::reset() {
    SumaUchybów = 0.0;
    PoprzedniUchyb = 0.0;
    OstatnieSterowanie = 0.0;
}

double PID::getOstatnieSterowanie() const {
    return OstatnieSterowanie;
}

void PID::setKp(double nowyKp) {
    Kp = nowyKp;
}

void PID::setTi(double nowyTi) {
    Ti = nowyTi;
}

void PID::setTd(double nowyTd) {
    Td = nowyTd;
}
