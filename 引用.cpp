#include <iostream>
using namespace std;

//交换函数

//1、值传递
void Swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

//2、地址传递
void Swap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3、引用传递
void Swap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{

	int a = 10;
	int b = 20;
	Swap01(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	Swap02(&a, &b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	Swap03(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	return 0;
}
