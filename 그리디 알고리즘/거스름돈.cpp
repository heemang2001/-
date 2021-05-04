#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int RemainMoney = 0; // ÀÜµ·
	int nValue = 0; // ÀÜµ· ¸Å¼ö
	int Money = 0; // ÁöºÒÇÒ µ· , 1 <= Money < 1000

	cin >> Money;

	RemainMoney = 1000 - Money;

	nValue += RemainMoney / 500;
	RemainMoney = RemainMoney % 500;

	nValue += RemainMoney / 100;
	RemainMoney = RemainMoney % 100;

	nValue += RemainMoney / 50;
	RemainMoney = RemainMoney % 50;

	nValue += RemainMoney / 10;
	RemainMoney = RemainMoney % 10;

	nValue += RemainMoney / 5;
	RemainMoney = RemainMoney % 5;

	nValue += RemainMoney;

	cout << nValue << '\n';

	return 0;
}