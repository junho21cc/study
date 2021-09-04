#include <iostream>

using namespace std;

class Circle
{
private:
	int radius;
public:
	Circle();
	Circle(int r);
	double getArea();
};

Circle::Circle(int r)
{
	radius = r;
}
Circle::Circle()
{
	radius = 1;
}
double Circle::getArea()
{
	return 3.14 * radius * radius;
}

int main()
{
	Circle donut;
	Circle pizza(30);

	cout << donut.getArea() << endl;

	Circle* p = &donut;

	cout << p->getArea() << endl;
	cout << (*p).getArea() << endl;


	return 0;
}