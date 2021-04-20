#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nCurTemper, nTargetTemper = 0;
	int nValue = 0;

	cin >> nCurTemper;
	cin >> nTargetTemper;

	int nTemp = abs(nTargetTemper) - abs(nCurTemper);
	nTemp = abs(nTemp);

	// 10��
	nValue += nTemp / 10;
	nTemp = nTemp % 10;

	//  5��, 1��
	// 
	//	1�� �Ǳ� ���ؼ��� + 1(1ȸ)
	//	2�� �Ǳ� ���ؼ��� + 1, +1(2ȸ)
	//	3�� �Ǳ� ���ؼ��� + 1, +1, +1 �Ǵ� + 5, -1, -1(3ȸ)
	//	4�� �Ǳ� ���ؼ��� + 5, -1(2ȸ)
	//	5�� �Ǳ� ���ؼ��� + 5(1ȸ)
	//	6�� �Ǳ� ���ؼ��� + 5, +1(2ȸ)
	//	7�� �Ǳ� ���ؼ��� + 5, +1, +1(3ȸ)
	//	8�� �Ǳ� ���ؼ��� + 10, -1, -1(3ȸ)
	//	9�� �Ǳ� ���ؼ��� + 10, -1(2ȸ)

	if (nTemp == 1 || nTemp == 5)
	{
		nValue += 1;
	}

	else if (nTemp == 2 || nTemp == 4 || nTemp == 6 || nTemp == 9)
	{
		nValue += 2;
	}

	else if (nTemp == 3 || nTemp == 7 || nTemp == 8)
	{
		nValue += 3;
	}

	cout << nValue;	

	return 0;
}