#include <iostream>

using namespace std;


class Person
{
public:
	//无参（默认）构造函数
	Person()
	{
		cout << "Person无参构造函数的调用" << endl;
	}
	//有参构造函数
	Person(int a)
	{
		age = a;
		cout << "Person有参构造函数的调用" << endl;
	}
	//拷贝构造函数
	Person(const Person &p)
	{
		//拷贝所有属性
		age = p.age;
		cout << "Person拷贝构造函数的调用" << endl;
	}
	//析构函数
	~Person()
	{
		cout << "Person析构函数的调用" << endl;
	}
//private:
	int age;
};

void test01()
{
	//括号法
	Person p1;	//无参（默认），注意：不要加（），否则会被编译器当作一个函数的声明
	Person p2(10);	//有参
	Person p3(p2);	//拷贝
	Person p6();

	cout << "p1 age:" << p1.age << endl;
	cout << "p2 age:" << p2.age << endl;
	cout << "p3 age:" << p3.age << endl;

	//显示法
	Person p1;	//无参
	Person p2 = Person(10);	//有参
	Person p3 = Person(p2);	//拷贝

	Person(10);	//匿名对象 特点：当前行结束后，系统会立即回收掉匿名对象
	//注意：不要利用拷贝构造函数初始化匿名对象	编译器会认为 Person(p2) 等价于 Person p2;
	Person(p2);

	//隐式转换法
	Person p4 = 10;	//有参，相当于 Person p4 = Person(10);
	Person p5 = p4;	//拷贝
}

int main()
{
	test01();

	system("pause");
	return 0;
}
