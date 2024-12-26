#include <iostream>
using namespace std;

//成员变量和成员函数分开存储
class Person
{

};

class Person01
{
	int mA;	//非静态成员变量，属于类的对象上
	static int mB;	//静态成员变量，不属于类的对象上
	void func(){}	//非静态成员函数，不属于类的对象上
	static void func2(){}	//静态成员函数，不属于类的对象上
};
int Person01::mB = 1;

void test()
{
	Person p;
	//C++编译器会为每个空对象分配 1 个字节内存空间
	cout << "size of p = " << sizeof(p) << endl;
}

void test01()
{
	Person01 p;
	cout << "size of p = " << sizeof(p) << endl;
}
int main()
{
	test01();

	system("pause");
	return 0;
}
