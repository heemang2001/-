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

	// 10도
	nValue += nTemp / 10;
	nTemp = nTemp % 10;

	//  5도, 1도
	// 
	//	1이 되기 위해서는 + 1(1회)
	//	2가 되기 위해서는 + 1, +1(2회)
	//	3이 되기 위해서는 + 1, +1, +1 또는 + 5, -1, -1(3회)
	//	4가 되기 위해서는 + 5, -1(2회)
	//	5가 되기 위해서는 + 5(1회)
	//	6이 되기 위해서는 + 5, +1(2회)
	//	7이 되기 위해서는 + 5, +1, +1(3회)
	//	8이 되기 위해서는 + 10, -1, -1(3회)
	//	9가 되기 위해서는 + 10, -1(2회)

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