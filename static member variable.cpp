#include <iostream>
using namespace std;
//#include <string>

//静态成员变量

//1.编译阶段就分配内存
class Person
{
public:
	static int mA;
//静态成员变量也有访问权限
private:
	static int mB;
};

//2.类内声明，类外初始化操作
int Person::mA = 100;
int Person::mB = 100;

//3.所有对象共享同一份内存
void test01()
{
	Person p;
	cout << p.mA << endl;
	Person p2;
	p2.mA = 200;
	cout << p.mA << endl;
}

//4.静态成员变量不专属于某个对象，有两种访问方式
void test02()
{
	//通过对象访问
	Person p;
	cout << p.mA << endl;
	//通过类名访问
	cout << Person::mA << endl;
}

int main()
{
	test02();

	system("pause");
	return 0;
}
