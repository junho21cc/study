#include "Exp.h"

Exp::Exp(int base, int exponential)
{
	Base = base;
	Exponential = exponential;

	Value = Base;
	for (int i = 1; i < Exponential; i++)
	{
		Value *= Base;
	}
}

Exp::Exp(int base)
{
	Base = base;
	Exponential = 1;
	Value = Base;
}
Exp::Exp()
{
	Base = 1;
	Exponential = 1;
	Value = 1;
}

int Exp::getValue()
{
	return Value;
}

int Exp::getBase()
{
	return Base;
}

int Exp::getExp()
{
	return Exponential;
}