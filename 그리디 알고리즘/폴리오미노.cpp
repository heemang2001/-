#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool bCheck = true;
string sAnswer;

string MakeAB(int num)
{
	string str1 = "";

	int nDivide_4 = 0;
	int nDivide_2 = 0;
	int nTemp = 0;

	// 4배수로 나눠지면
	if (num % 4 == 0 && num / 4 > 0)
	{
		nDivide_4 = num / 4;

		for (int i = 0; i < nDivide_4; i++)
		{
			str1 += "AAAA";
		}	

		return str1;
	}

	if (num % 4 >= 1)
	{
		nDivide_4 = num / 4;
		num = num - (nDivide_4 * 4);
		
		for (int i = 0; i < nDivide_4; i++)
		{
			str1 += "AAAA";
		}
	}	

	if(num % 2 == 0 && num > 0)
	{
		nDivide_2 = num / 2;

		for (int i = 0; i < nDivide_2; i++)
		{
			str1 += "BB";
		}
	}

	return str1;
}

void Solution(string str)
{
	int nTemp = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'X')
		{
			nTemp++;
		}

		else if(str[i] == '.')
		{
			if (nTemp > 0 && nTemp % 2 == 0)
			{
				sAnswer += MakeAB(nTemp);
			}
			
			else if (nTemp % 2 == 1)
			{
				bCheck = false;
			}

			sAnswer += '.';
			nTemp = 0;
		}
	}

	if (nTemp > 0 && nTemp % 2 == 0)
	{
		sAnswer += MakeAB(nTemp);
	}

	else if (nTemp % 2 == 1)
	{
		bCheck = false;
	}
}

int main()
{
	string sTemp;

	cin >> sTemp;

	Solution(sTemp);

	if (bCheck)
	{
		cout << sAnswer << '\n';
	}

	else
	{
		cout << -1 << '\n';
	}

	return 0;
}