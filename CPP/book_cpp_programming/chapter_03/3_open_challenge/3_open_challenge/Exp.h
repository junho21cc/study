#pragma once


class Exp
{
private:
	int Exponential, Base, Value;
public:
	Exp(int base = 1, int exponential = 1);
	int getBase();
	int getExp();
	int getValue();
};