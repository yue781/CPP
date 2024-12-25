#include <iostream>
using namespace std;

//浅拷贝与深拷贝
//浅拷贝带来的问题：堆区内存重复释放
class Person
{
public:
	Person()
	{
		cout << "默认构造函数" << endl;
	}
	Person(int age, int hei)
	{
		Age = age;
		height = new int(hei);
		cout << "有参构造函数" << endl;
	}
	Person(const Person& p)
	{
		Age = p.Age;
		//height = p.height;	//浅拷贝：编译器默认实现的代码
		height = new int(*p.height);	//深拷贝
		cout << "拷贝构造函数" << endl;
	}
	~Person()	//析构对堆区数据做释放操作
	{
		if (height != NULL)
		{
			delete height;
			height = NULL;
		}
		cout << "析构函数" << endl;
	}

	int Age;
	int* height;
};

void test01()
{
	Person p1(18,160);
	cout << "p1 age:" << p1.Age << "	p1 height" << *p1.height << endl;

	Person p2(p1);
	cout << "p2 age:" << p2.Age << "	p2 height" << *p2.height << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
