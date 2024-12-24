#include <iostream>
using namespace std;

//函数重载：函数名相同，提高复用性
//同一作用域，函数名称相同，函数参数类型不同，或个数不同，或顺序不同

// 函数的返回值不可以作为函数重载的条件
int func(int)
{
	cout << "hello C++" << endl;
}

void func(double)
{
	cout << "func(double)调用" << endl;
}

void func(int)
{
	cout << "func(int)调用" << endl;
}

//函数重载的注意事项
//1.引用作为重载的条件
void func(int& a)
{
	cout << "func(int& a)调用" << endl;
}

void func(const int& a)
{
	cout << "func(const int& a)调用" << endl;
}

//2.函数重载碰到默认参数
void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 1)调用" << endl;
}

void func2(int a)
{
	cout << "func2(int a)调用" << endl;
}

int main()
{
	int a = 10;
	func(a);

	func(1);

	func2(1);

	return 0;
}
