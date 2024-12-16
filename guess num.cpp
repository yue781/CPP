#include <iostream>
using namespace std;
#include <ctime>

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;	//生成1~100的随机数
	int guess = 0;

	while (1) {
		cin >> guess;
		if (guess > num) {
			cout << "猜大了！" << endl;
		}
		else if (guess < num) {
			cout << "猜小了！" << endl;
		}
		else {
			cout << "猜对了！" << endl;
			break;
		}
	}

	return 0;
}
