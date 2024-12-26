#include <iostream>
using namespace std;


//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量

class Person
{
public:
	static void func()
	{
		mA = 100;
		//mB = 200;//静态成员函数不可以访问非静态成员变量，因为无法区分到底是哪个对象的成员变量
		cout << "static void func" << endl;
	}
	static int mA;
	int mB;
	//静态成员函数具有访问权限
private:
	static void func2()
	{
		cout << "static void func2" << endl;
	}
};
int Person::mA = 0;

void test01()
{	
	//通过对象访问
	Person p;
	p.func();
	//通过类名访问
	Person::func();
	Person::func2();
}

int main()
{
	test01();

	system("pause");
	return 0;
}
