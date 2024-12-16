#include <iostream>
using namespace std;

int main()
{
	int num = 100;
	while (num < 1000) {
		int ge = num % 10;	//获取个位
		int shi = num / 10 % 10;	//获取十位
		int bai = num / 100;	//获取百位
		if (ge * ge * ge + shi * shi * shi + bai * bai * bai == num) {
			cout << num << endl;
		}
		num++;
	}

	return 0;
}
