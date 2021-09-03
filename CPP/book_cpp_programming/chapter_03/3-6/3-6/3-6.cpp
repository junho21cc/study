#include <iostream>

using namespace std;

class rectangle
{
public:
	int width, height;
	rectangle();
	rectangle(int w, int h);
	rectangle(int length);
	bool issquare();
};

rectangle::rectangle()
{
	width = height = 1;
}
rectangle::rectangle(int w, int h)
{
	width = w;
	height = h;
}

rectangle::rectangle(int length)
{
	width = height = length;
}

bool rectangle::issquare()
{
	if (width == height)
		return true;
	else
		return false;
}

int main()
{
	rectangle rect1;
	rectangle rect2(3, 5);
	rectangle rect3(3);

	if (rect1.issquare())
		cout << "rect1은 정사각형이다" << endl;
	if (rect2.issquare())
		cout << "rect2은 정사각형이다" << endl;
	if (rect3.issquare())
		cout << "rect3은 정사각형이다" << endl;
	return 0;
}