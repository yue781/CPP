#include <iostream>
using namespace std;

//常量引用：用于修饰形参，防止误操作
void showValue1(int& val)
{
	val = 1000;
	cout << "val=" << val << endl;
}

void showValue2(const int& val)
{
	val = 1000;
	cout << "val=" << val << endl;
}

int main()
{
	int& ref = 10;	//引用必须引一块合法的内存空间
	//加上const之后，编译器将代码修改为 int temp = 10; const int& ref = temp;
	const int& ref2 = 10;
	ref2 = 20;	//加入const之后变为只读，不可修改

	int a = 100;
	showValue1(a);
	cout << "a=" << a << endl;

	return 0;
}
