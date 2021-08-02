#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

long long N, M, S;
long long sum;
long long answer;

bool Compare(pair<long long, long long> n1, pair<long long, long long> n2)
{
	return n1.first - n1.second < n2.first - n2.second;
}

int main()
{
	cin >> N >> M >> S;

	vector<pair<long long, long long>> vecMap;	

	for (long long i = 0; i < N; i++)
	{
		long long nTemp1;
		long long nTemp2;

		cin >> nTemp1 >> nTemp2;

		vecMap.push_back({ nTemp1, nTemp2 });
	}		

	sort(vecMap.begin(), vecMap.end(), Compare);

	priority_queue<long long> q;
	for (long long i = 0; i < N; i++)
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

	priority_queue<long long>().swap(q);
	sum = 0;
	for (long long i = N; --i >= 0;)
	{
		q.push(-vecMap[i].first);
		sum += vecMap[i].first;

		while (q.size() > M)
		{
			sum += q.top();
			q.pop();
		}

		answer = max(answer, sum + (i ? vecMap[i - 1].second : 0LL));
	}

	cout << answer << '\n';

	return 0;
}