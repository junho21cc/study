#include <iostream>

using namespace std;

class circle
{
public:
	int radius;
	circle();
	circle(int r);
	~circle();
	double getArea();
};

circle::circle()
{
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

circle::circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

circle::~circle()
{
	cout << "반지름 " << radius << " 원 소멸" << endl;
}

double circle::getArea()
{
	return 3.14 * radius * radius;
}

circle global_donut(1000);
circle global_pizza(2000);


int main()
{
	circle donut;
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	circle pizza(30);

	return 0;
}