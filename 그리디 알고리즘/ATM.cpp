#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int N;
	int nTime;
	int nValue = 0;

	vector <int> v;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> nTime;
		v.push_back(nTime);
	}

	sort(v.begin(), v.end());

	//for (int i = 0; i < v.size(); i++)
	//{
	//	cout << v[i] << endl;;
	//}

	while (N > 0)
	{
		for (int i = N - 1; i >= 0; i--)
		{
			nValue += v[i];
		}

		N--;
	}

	cout << nValue;
}