#include <iostream>

using namespace std;

class Circle
{
private:
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r);
	double getArea();
};

void Circle::setRadius(int r)
{
	radius = r;
}

Circle::Circle(int r)
{
	radius = r;
	cout << "积己磊 角青 " << radius << endl;
}
Circle::Circle()
{
	radius = 1;
}
Circle::~Circle()
{
	cout << "家戈磊 角青 radius" << radius << endl;
}
double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main()
{
	Circle* pArray = new Circle[3];

	pArray[0].setRadius(10);
	pArray[1].setRadius(20);
	pArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)
	{
		cout << pArray[i].getArea() << endl;
	}
	Circle* p = pArray;
	for (int i = 0; i < 3; i++)
	{
		cout << p->getArea() << endl;
		p++;
	}

	delete[] pArray;

	return 0;
}