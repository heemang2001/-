#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<string> vecOne;
vector<string> vecZero;

int Solution(string str)
{
	int answer = 0;	
	string sTemp;
	sTemp += str[0];

	for (int i = 1; i < str.size(); i++)
	{
		if (sTemp[0] == '0' && str[i] == '0')
		{
			sTemp += '0';
		}

		else if (sTemp[0] == '1' && str[i] == '1')
		{
			sTemp += '1';
		}

		else if (sTemp[0] == '0' && str[i] == '1')
		{
			vecZero.push_back(sTemp);			
			sTemp = "1";
		}

		else if (sTemp[0] == '1' && str[i] == '0')
		{
			vecOne.push_back(sTemp);			
			sTemp = "0";
		}
	}

	if (sTemp[0] == '0')
	{
		vecZero.push_back(sTemp);
	}

	else if (sTemp[0] == '1')
	{
		vecOne.push_back(sTemp);
	}

	answer = min(vecOne.size(), vecZero.size());

	return answer;
}

int main()
{
	string str1;

	cin >> str1;

	cout << Solution(str1) << '\n';

	return 0;
}