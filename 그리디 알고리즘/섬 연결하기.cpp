#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int d[101];

int getParent(int node)
{
	if (node == d[node])
	{
		return node;
	}

	else
	{
		return d[node] = getParent(d[node]);
	}
}

bool compare(vector<int> a, vector<int> b)
{
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs)
{
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		d[i] = i;
	}

	sort(costs.begin(), costs.end(), compare);

	for (int i = 0; i < costs.size(); i++)
	{
		int start = getParent(costs[i][0]);
		int end = getParent(costs[i][1]);
		int cost = costs[i][2];

		if (start != end)
		{
			d[end] = start;

			answer += cost;
		}
	}

	return answer;
}
