#include <iostream>
using namespace std;

class rectangle
{
public:
	int width;
	int height;
	int getArea();
};

int rectangle::getArea()
{
	return width * height;
}

int main()
{
	rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "�簢���� ������ " << rect.getArea() << endl;

	return 0;
}