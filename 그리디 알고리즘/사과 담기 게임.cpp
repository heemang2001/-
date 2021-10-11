#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N, M, J;
int Answer;
vector<int> vecApple;

int main()
{
	cin >> N >> M >> J;
	
	for (int i = 0; i < J; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecApple.push_back(nTemp);
	}

	int cur_Basket = 1;

	for (int i = 0; i < vecApple.size(); i++)
	{
		while (1)
		{
			if (cur_Basket <= vecApple[i] && cur_Basket + (M - 1) >= vecApple[i])
			{
				break;
			}

			else if (cur_Basket + (M - 1) < vecApple[i])
			{
				cur_Basket++;
				Answer++;
			}

			else if (cur_Basket > vecApple[i])
			{
				cur_Basket--;
				Answer++;
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}