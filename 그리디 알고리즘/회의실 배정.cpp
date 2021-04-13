#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N, end, begin;

	vector<pair<int, int>> schedule;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> begin >> end;
		schedule.push_back(make_pair(end, begin));
	}

	sort(schedule.begin(), schedule.end());

	cout << "SORT" << endl;

	for (int i = 0; i < schedule.size(); i++)
	{
		cout << schedule[i].first << " " << schedule[i].second << endl;
	}

	int time = schedule[0].first; // 4, 8, 12
	int count = 1;
	for (int i = 1; i < N; i++)
	{
		if (time <= schedule[i].second)
		{
			count++;
			time = schedule[i].first;
		}
	}

	cout << count;
}