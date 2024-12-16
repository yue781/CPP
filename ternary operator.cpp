#include <iostream>
using namespace std;

int main()
{
	//三目运算符
	int a = 10, b = 20, c = 0;
	c = a > b ? a : b;	//等价于c = ( (a > b) ? a : b)
	cout << "c = " << c << endl;

	//在C++中三目运算符返回的是变量
	a > b ? a : b = 100;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	return 0;
}
