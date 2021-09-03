#pragma once


class Exp
{
private:
	int Exponential, Base, Value;
public:
	Exp(int base, int exponential);
	Exp(int base);
	Exp();
	int getBase();
	int getExp();
	int getValue();
};