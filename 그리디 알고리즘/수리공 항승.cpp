#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int L; // 0 <= N,L <= 1000 

int main()
{
	cin >> N >> L;

	vector<pair<int, int>> vecWater;	

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecWater.push_back({nTemp,0});
	}

	sort(vecWater.begin(), vecWater.end());

	int Lenth = L;
	bool bConnect = false;

	if (N > 1)
	{
		vecWater[0].second = 1;
		for (int i = 0; i < vecWater.size() - 1; i++)
		{
			int nTemp = vecWater[i + 1].first + 0.5 - (vecWater[i].first - 0.5);
			int nTemp2 = vecWater[i + 1].first + 0.5 - (vecWater[i].first + 0.5);

			if (Lenth >= nTemp2 && bConnect)
			{
				Lenth -= nTemp2;
				vecWater[i + 1].second = vecWater[i].second;
			}

			// 이을수 있으면
			else if (Lenth >= nTemp && !bConnect)
			{
				Lenth -= nTemp;
				vecWater[i + 1].second = vecWater[i].second;
				bConnect = true;
			}

			// 이을수 없으면
			else
			{
				Lenth = L;
				vecWater[i + 1].second = vecWater[i].second + 1;
				bConnect = false;
			}
		}

		cout << vecWater[N - 1].second << '\n';
	}

	else
	{
		cout << 1 << '\n';		
	}

	return 0;
}