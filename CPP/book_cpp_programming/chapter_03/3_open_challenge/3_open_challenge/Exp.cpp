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