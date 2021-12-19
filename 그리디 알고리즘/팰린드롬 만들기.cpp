#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string Answer;
string sInput;
map<char, int> mapTemp;

int main()
{
	cin >> sInput;	

	for (int i = 0; i < sInput.size(); i++)
	{
		mapTemp[sInput[i]]++;
	}

	int strSize = sInput.size();

	if (strSize % 2 == 0)
	{
		for (auto iter : mapTemp)
		{
			if (iter.second % 2 == 1)
			{
				Answer = "I'm Sorry Hansoo";
				cout << Answer << '\n';
				return 0;
			}

			int cnt = iter.second / 2;

			while (cnt > 0)
			{
				Answer += iter.first;
				cnt--;
			}
		}

		string Answer_1 = Answer;
		reverse(Answer.begin(), Answer.end());

		Answer = Answer_1 + Answer;
	}

	else
	{
		bool bFindMid = false;
		string strMid = "";

		for (auto iter : mapTemp)
		{
			if (iter.second % 2 == 1 && bFindMid == false)
			{
				bFindMid = true;
				strMid = iter.first;
			}

			else if (iter.second % 2 == 1 && bFindMid == true)
			{
				Answer = "I'm Sorry Hansoo";
				cout << Answer << '\n';
				return 0;
			}

			int cnt = iter.second / 2;

			while (cnt > 0)
			{
				Answer += iter.first;
				cnt--;
			}
		}

		string Answer_1 = Answer;
		reverse(Answer.begin(), Answer.end());

		Answer = Answer_1 + strMid + Answer;
	}

	cout << Answer << '\n';

	return 0;
}