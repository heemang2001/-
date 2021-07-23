#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int answer;

int main()
{
	string sTemp1;
	string sTemp2;

	getline(cin, sTemp1);
	getline(cin, sTemp2);

	int stringLenth = sTemp2.size();

	for (int i = 0; i < sTemp1.size(); i++)
	{
		string sTemp3;

		for (int j = i; j < i + stringLenth; j++)
		{
			if (j >= sTemp1.size())
			{
				break;
			}

			sTemp3 += sTemp1[j];

			if (sTemp3 == sTemp2)
			{
				answer++;
				i += (stringLenth-1);
				break;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}