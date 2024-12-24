#include <iostream>
//#include <string>

using namespace std;

class Cube
{
public:
	void set_LWH(int l,int w,int h)
	{
		L = l;
		W = w;
		H = h;
	}
	int get_LWH()
	{
		return L, W, H;
	}
	int calcuS()
	{
		return 2 * (L * W + W * H + L * H);
	}
	int calcuV()
	{
		return L * W * H;
	}
	bool isSame_class(Cube& c)
	{
		if (get_LWH() == c.get_LWH())
		{
			return true;
		}
		return false;
	}
private:
	int L;
	int W;
	int H;
};

bool isSame(Cube& c1, Cube& c2)
{
	if (c1.get_LWH() == c2.get_LWH())
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1, c2;
	c1.set_LWH(10, 10, 10);
	c2.set_LWH(10, 10, 12);

	cout << "S of C1:" << c1.calcuS() << endl;
	cout << "V of C1:" << c1.calcuV() << endl;

	bool res = isSame(c1, c2);//全局函数判断
	if (res)
	{
		cout << "c1 equal c2" << endl;
	}
	else
	{
		cout << "c1 not equal c2" << endl;
	}

	res = c1.isSame_class(c2);//成员函数判断
	if (res)
	{
		cout << "c1 equal c2" << endl;
	}
	else
	{
		cout << "c1 not equal c2" << endl;
	}
	return 0;
}
