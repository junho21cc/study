#include <iostream>

using namespace std;

#include "Exp.h"

int main()
{
	Exp a(3, 2);
	Exp b(9);
	Exp c;

	cout << "a의 value" << a.getValue() << endl;
	cout << "b의 value" << b.getValue() << endl;
	cout << "c의 value" << c.getValue() << endl;
	cout << endl;
	cout << "a의 base" << a.getBase() << endl;
	cout << "b의 base" << b.getBase() << endl;
	cout << "c의 base" << c.getBase() << endl;
	cout << endl;
	cout << "a의 Exp" << a.getExp() << endl;
	cout << "b의 Exp" << b.getExp() << endl;
	cout << "c의 Exp" << c.getExp() << endl;


	return 0;
}
