#include <iostream>
using namespace std;


class Person
{
public:
	Person(int age)
	{
		//this指针指向 被调用成员函数 所属的对象
		this->age = age;
	}

	Person& AddAge01(Person& p)//返回自身的引用
	{
		this->age += p.age;
		return *this;
	}

	Person AddAge02(Person& p)//返回自身的拷贝
	{
		this->age += p.age;
		return *this;
	}

	int age;
};

//1.解决名称冲突
void test01()
{
	Person p(18);
	cout << "p age:" << p.age << endl;
}
//2.返回对象本身用 *this
void test02()
{
	Person p1(10);
	Person p2(10);
	//链式编程思想
	p2.AddAge01(p1).AddAge01(p1).AddAge01(p1);
	cout << "p2 age:" << p2.age << endl;
	p2.AddAge02(p1).AddAge02(p1).AddAge02(p1);
	cout << "p2 age:" << p2.age << endl;
}
int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}
