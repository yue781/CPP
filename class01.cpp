#include <iostream>
//#include <string>

using namespace std;

class Person
{

public:
	void setName(string name)
	{
		Name = name;
	}
	
	string getName()
	{
		return Name;
	}

	int getAge()
	{
		return Age;
	}

	void setIdol(string idol)
	{
		Idol = idol;
	}

	void setNum(int num)
	{
		if (0 < num && num < 100)
		{
			Num = num;
		}
		else
		{
			cout << "输入非法" << endl;
		}
	}

private:
	string Name;//可读可写

	int Age = 18;//只读

	int Num;//只写，但需要检测数据有效性

	string Idol;//只写
};

int main()
{
	Person p;
	p.setName("张三");
	p.setIdol("faker");
	p.setNum(100);
	cout << "name:" << p.getName() << endl;
	cout << "age:" << p.getAge() << endl;
	return 0;
}
