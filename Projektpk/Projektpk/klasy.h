#pragma once
#include<iostream>

class Sprzerzenie
{
	Arx* m_model;
	Pid* m_pid;
	Sygnal* m_sygnal;
public:
	double uchyb();
	double wynikSprzerzenia();

};
class Arx
{
	double a;
	double b;
	int k;
	double z = 0;
	double y;
public:
	double wspolczynnikA();
	double wspolczynnikB();
	double wspolczynnikU();
	double wspolczynnikZ();
	int wspolczynnikK();
	double calosc();
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
