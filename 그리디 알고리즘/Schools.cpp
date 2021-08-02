#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, M, S;
int sum;
int answer;

bool Compare(pair<int, int> n1, pair<int, int> n2)
{
	return n1.first - n1.second < n2.first - n2.second;
}

int main()
{
	cin >> N >> M >> S;

	vector<pair<int, int>> vecMap;	

	for (int i = 0; i < N; i++)
	{
		int nTemp1;
		int nTemp2;

		cin >> nTemp1 >> nTemp2;

		vecMap.push_back({ nTemp1, nTemp2 });
	}		

	sort(vecMap.begin(), vecMap.end(), Compare);

	priority_queue<int> q;
	for (int i = 0; i < N; i++)
	{
		q.push(-vecMap[i].second);
		sum += vecMap[i].second;

		while (q.size() > S)
		{
			sum += q.top();
			q.pop();
		}

		vecMap[i].second = sum;
	}

	priority_queue<int>().swap(q);
	sum = 0;
	for (int i = N; --i >= 0;)
	{
		q.push(-vecMap[i].first);
		sum += vecMap[i].first;

		while (q.size() > M)
		{
			sum += q.top();
			q.pop();
		}

		answer = max(answer, sum + (i ? vecMap[i - 1].second : 0));
	}

	cout << answer << '\n';

	return 0;
}