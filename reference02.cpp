#include <iostream>
using namespace std;

//1、不要返回局部变量的引用
int& test01()
{
	int a = 10;//局部变量存放在栈区，栈区的数据由编译器自动分配释放
	return a;
}

//2、如果函数的返回值是引用，那么函数的调用可以作为左值
int& test02()
{
	static int a = 10;//静态变量存放在全局区，全局区的数据在程序结束后由系统释放
	return a;
}
int main()
{
	int& ref = test01();
	cout << "ref=" << ref << endl;//第一次打印结果正确，因为编译器做了保留
	cout << "ref=" << ref << endl;//第二次打印结果错误，因为a的内存已经释放

	int& ref2 = test02();
	cout << "ref2=" << ref2 << endl;
	cout << "ref2=" << ref2 << endl;

	test02() = 1000;//test02()可以理解为a的一个引用
	cout << "ref2=" << ref2 << endl;
	cout << "ref2=" << ref2 << endl;

	return 0;
}
