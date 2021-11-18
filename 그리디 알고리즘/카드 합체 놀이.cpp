#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N, M;	// ī�尳�� N // ī����ü ��� M
long long Answer;

int main()
{
	cin >> N >> M;

	vector<long long> vecCard;

	for (int i = 0; i < N; i++)
	{
		long long nTemp;
		cin >> nTemp;
		vecCard.push_back(nTemp);
	}

	for (int i = 0; i < M; i++)
	{
		sort(vecCard.begin(), vecCard.end());

		long long sum = vecCard[0] + vecCard[1];
		vecCard[0] = sum;
		vecCard[1] = sum;
	}

	for (int i = 0; i < vecCard.size(); i++)
	{
		Answer += vecCard[i];
	}

	cout << Answer << '\n';
	
	return 0;
}