#include <iostream>
#include <vector>
#include <algorithm>

// A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7

using namespace std;

int N;
int alpha[26]; // 어떤 알파벳 사용?

int solution(vector<string>& vecString)
{
	int answer = 0;

	for (int i = 0; i < vecString.size(); i++)
	{

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