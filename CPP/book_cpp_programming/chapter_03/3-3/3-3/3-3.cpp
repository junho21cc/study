#include <iostream>

using namespace std;

class circle
{
public:
	int radius;
	circle();
	circle(int r);
	double getArea();
};

circle::circle()
{
	radius = 1;
	cout << "������ " << radius << " �� ����" << endl;
}

circle::circle(int r)
{
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}

double circle::getArea()
{
	return 3.14 * radius * radius;
}

int main()
{
	circle donut;
	double area = donut.getArea();
	cout << "donut ������ " << area << endl;

	circle pizza(30);
	area = pizza.getArea();
	cout << "pizza ������ " << area << endl;

	return 0;
}