#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int alpha[26]; // 어떤 알파벳 사용?

int solution(vector<string>& vecString)
{
	int answer = 0;

	for (int i = 0; i < vecString.size(); i++)
	{
		string sTemp = vecString[i];
		int lengh = sTemp.length();
		int pow = 1;

		for (int j = lengh - 1; j >= 0; j--)
		{
			int nTemp = sTemp[j] - 'A';
			alpha[nTemp] = alpha[nTemp] + pow;
			pow = pow * 10;
		}
	}

	sort(alpha, alpha + 26, greater<int>());

	int Number = 9;

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] == 0)
		{
			break;
		}

		answer = answer + (alpha[i] * Number);
		Number--;
	}

	return answer;
}

int main()
{
	vector<string> vecString;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string sTemp;
		cin >> sTemp;
		vecString.push_back(sTemp);
	}

	cout << solution(vecString) << '\n';

	return 0;
}