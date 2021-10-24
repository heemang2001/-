#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N;
int Answer;

// ����(0) ==> ����(1) ==> �ٳ���(2) ==> ����(0)
int main()
{
	cin >> N;

	int curMilk = 0;

	vector<int> vecTemp;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecTemp.push_back(nTemp);
	}

	for (int i = 0; i < vecTemp.size(); i++)
	{
		if (curMilk == vecTemp[i])
		{
			curMilk++;
			Answer++;

			if (curMilk > 2)
			{
				curMilk = 0;
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}