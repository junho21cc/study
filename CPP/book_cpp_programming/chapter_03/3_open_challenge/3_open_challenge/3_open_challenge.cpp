#include <iostream>

using namespace std;

#include "Exp.h"

int main()
{
	Exp a(3, 2);
	Exp b(9);
	Exp c;

	cout << "a�� value" << a.getValue() << endl;
	cout << "b�� value" << b.getValue() << endl;
	cout << "c�� value" << c.getValue() << endl;
	cout << endl;
	cout << "a�� base" << a.getBase() << endl;
	cout << "b�� base" << b.getBase() << endl;
	cout << "c�� base" << c.getBase() << endl;
	cout << endl;
	cout << "a�� Exp" << a.getExp() << endl;
	cout << "b�� Exp" << b.getExp() << endl;
	cout << "c�� Exp" << c.getExp() << endl;


	return 0;
}
