#include <iostream>

using namespace std;

class point
{
	int x, y;
public:
	point();
	point(int a, int b);
	void show()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
};

point::point():point(0, 0) {}

point::point(int a, int b): x(a), y(b){}

int main()
{
	point origin;
	point target(10, 20);
	origin.show();
	target.show();
}