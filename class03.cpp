#include <iostream>

using namespace std;

//点类
class Point
{
public:
	void set_XY(int x, int y)
	{
		X = x;
		Y = y;
	}
	int get_XY()
	{
		return X, Y;
	}
private:
	int X;
	int Y;
};

//圆类
class Circle
{
public:
	void set_R(int r)
	{
		R = r;
	}
	int get_R()
	{
		return R;
	}
	void set_Center(Point center)
	{
		Center = center;
	}
	Point get_Center()
	{
		return Center;
	}
private:
	int R;
	Point Center;
};

//点和圆的关系
void isInCircle(Circle& c, Point& p)
{
	int c_X = 0, c_Y = 0, p_X = 0, p_Y = 0;
	c_X, c_Y = c.get_Center().get_XY();
	p_X, p_Y = p.get_XY();
	int dist = (c_X - p_X) * (c_X - p_X) + (c_Y - p_Y) * (c_Y - p_Y);
	int rdist = c.get_R() * c.get_R();
	if (dist == rdist)
	{
		cout << "on the circle" << endl;
	}
	else if(dist > rdist)
	{
		cout << "out the circle" << endl;
	}
	else
	{
		cout << "in the circle" << endl;
	}
}

int main()
{
	Circle c;
	c.set_R(10);
	Point center;
	center.set_XY(10, 0);
	c.set_Center(center);

	Point p;
	p.set_XY(10, 9);

	isInCircle(c, p);

	return 0;
}
