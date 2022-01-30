#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int Answer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vector<int> vecTemp;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecTemp.push_back(nTemp);
	}	

	sort(vecTemp.begin(), vecTemp.end());

	// Â¦¼ö°³¸é
	if (vecTemp.size() % 2 == 0)
	{
		int left_Answer = 0;
		int right_Answer = 0;
		int left_index = vecTemp.size() / 2 - 1;
		int right_index = vecTemp.size() / 2;

		for (int i = 0; i < N; i++)
		{
			left_Answer += abs(vecTemp[left_index] - vecTemp[i]);
		}

		for (int i = 0; i < N; i++)
		{
			right_Answer += abs(vecTemp[right_index] - vecTemp[i]);
		}

		Answer = (left_Answer <= right_Answer) ? vecTemp[left_index] : vecTemp[right_index];
	}

	// È¦¼ö°³¸é
	else
	{
		Answer = vecTemp[vecTemp.size() / 2];
	}

	cout << Answer << '\n';

	return 0;
}