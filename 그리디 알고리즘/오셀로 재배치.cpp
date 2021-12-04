#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int T;

int main()
{
	cin >> T;

	vector<int> vecAnswer;

	for (int i = 0; i < T; i++)
	{
		int N;
		int Answer = 0;
		int cnt_differ = 0;
		int cnt_W1 = 0;
		int cnt_W2 = 0;

		cin >> N;

		string sTemp1;
		string sTemp2;

		cin >> sTemp1 >> sTemp2;

		for (int j = 0; j < N; j++)
		{
			if (sTemp1[j] != sTemp2[j])
			{
				cnt_differ++;
			}

			if (sTemp1[j] == 'W')
			{
				cnt_W1++;
			}

			if (sTemp2[j] == 'W')
			{
				cnt_W2++;
			}
		}

		Answer = (cnt_differ + abs(cnt_W1 - cnt_W2)) / 2;
		vecAnswer.push_back(Answer);
	}

	for (int i = 0; i < T; i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}