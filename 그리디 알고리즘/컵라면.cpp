#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
pair<int, int> a[200001];
priority_queue<int> pq;

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a + n);

	for (int j = 0; j < n; j++)
	{
		int dead = a[j].first;
		pq.push(-a[j].second);

		if (pq.size() > dead)
		{
			pq.pop();
		}
	}

	int ans = 0;

	while (!pq.empty())
	{
		ans += pq.top(); pq.pop();
	}

	cout << -ans << '\n';
}