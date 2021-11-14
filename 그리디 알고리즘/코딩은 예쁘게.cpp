#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N;
int Answer;
int g_index;

void DFS(vector<int>& vecTemp, int index)
{
	if (index >= N)
	{		
		return;
	}

	else if(vecTemp[index] > 0 )
	{
		vecTemp[index]--;

		if (index + 1 < N && vecTemp[index + 1] > 0)
		{
			DFS(vecTemp, index + 1);
		}		
	}

	else if (vecTemp[index] < 0 )
	{
		vecTemp[index]++;

		if (index + 1 < N && vecTemp[index + 1] < 0)
		{
			DFS(vecTemp, index + 1);
		}		
	}
}

int main()
{
	cin >> N;

	vector<int> vecTab;
	vector<int> vecGood;
	vector<int> vecDiffer;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecTab.push_back(nTemp);
	}

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecGood.push_back(nTemp);
	}

	for (int i = 0; i < N; i++)
	{
		int differ = vecGood[i] - vecTab[i];
		vecDiffer.push_back(differ);
	}	

	while (1)
	{			
		int cnt = count(vecDiffer.begin(), vecDiffer.end(), 0);

		if (cnt == N)
		{
			break;
		}

		DFS(vecDiffer, g_index);

		while (1)
		{
			if (vecDiffer[g_index] == 0)
			{
				g_index++;
			}

			if (g_index >= N || vecDiffer[g_index] != 0)
			{
				break;
			}
		} 

		Answer++;
	}

	cout << Answer << '\n';

	return 0;
}