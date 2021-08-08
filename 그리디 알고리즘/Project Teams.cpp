#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int answer = 987654321;
vector<int> vecCoding;

int main()
{
	cin >> N;

	for (int i = 0; i < 2 * N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecCoding.push_back(nTemp);
	}

	sort(vecCoding.begin(), vecCoding.end());

	for (int i = 0; i < N; i++)
	{
		answer = min(answer, vecCoding.front() + vecCoding.back());
		vecCoding.erase(vecCoding.begin());
		vecCoding.erase(vecCoding.end() - 1);
	}

	cout << answer << '\n';

	return 0;
}