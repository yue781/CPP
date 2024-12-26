#include <iostream>
using namespace std;
//#include <string>

//其他类对象作为本类的成员，先构造其他类，再构建本类，析构顺序相反

class Phone
{
public:
	Phone(string name)
	{
		PName = name;
		cout << "Phone构造函数的调用" << endl;
	}
	~Phone()
	{
		cout << "Phone析构函数的调用" << endl;
	}
	string PName;
};

class Person
{
public:
	Person(string name, string pName):m_Name(name), m_Phone(pName)
	{
		cout << "Person构造函数的调用" << endl;
	}
	~Person()
	{
		cout << "Person析构函数的调用" << endl;
	}
	string m_Name;
	Phone m_Phone;
};

void test01()
{
	Person p("lily", "Apple");
	cout << p.m_Name << " take " << p.m_Phone.PName << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}
