#pragma once

#ifndef PID_H
#define PID_H

class PID {
private:
    double Kp, Ti, Td;
    double SumaUchybów, PoprzedniUchyb, OstatnieSterowanie;

public:
    PID(double Kp, double Ti, double Td);
    double obliczSterowanie(double uchyb, double deltaT);
    void reset();
    double getOstatnieSterowanie() const;
    void setKp(double nowyKp);
    void setTi(double nowyTi);
    void setTd(double nowyTd);
};

#endif
