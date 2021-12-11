#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

#define MAX_VALUE 100001

using namespace std;

int G, P;
int Answer;
int parent[MAX_VALUE];

int Find(int num)
{
	if (num == parent[num])
	{
		return num;
	}

	return parent[num] = Find(parent[num]);
}

int main()
{
	cin >> G >> P;

	for (int i = 1; i <= G; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= P; i++)
	{
		int nTemp;
		cin >> nTemp;

		if (!Find(nTemp))
		{
			break;
		}

		else
		{
			Answer++;
			parent[Find(nTemp)] = Find(Find(nTemp) - 1);
		}
	}

	cout << Answer << '\n';
}


//int main()
//{
//	cin >> G >> P;
//
//	vector<int> vecAirplane;
//	queue<int> Q;
//
//	bool bGate[MAX_VALUE] = { false, };
//
//	for (int i = 0; i < P; i++)
//	{
//		int nTemp;
//		cin >> nTemp;
//		vecAirplane.push_back(nTemp);
//	}
//
//	sort(vecAirplane.begin(), vecAirplane.end());
//
//	for (int i = 0; i < vecAirplane.size(); i++)
//	{
//		Q.push(vecAirplane[i]);
//	}
//
//	for (int i = 1; i <= G; i++)
//	{
//		if (!Q.empty())
//		{
//			if (!bGate[i] && Q.front() >= i)
//			{
//				bGate[i] = true;
//				Q.pop();
//				Answer++;
//			}
//
//			else
//			{
//				Q.pop();
//			}
//		}
//	}
//
//	cout << Answer << '\n';
//
//	return 0;
//}