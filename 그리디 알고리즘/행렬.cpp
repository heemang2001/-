#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
int answer = 0;

string arrA[51];
string arrB[51];

void flip(int x, int y)
{
	answer++;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arrA[x + i][y + j] == '0')
			{
				arrA[x + i][y + j] = '1';
			}

			else
			{
				arrA[x + i][y + j] = '0';
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	bool flag = false;

	for (int i = 0; i < N; i++)
	{
		string sTemp;
		cin >> sTemp;
		arrA[i] += sTemp;
	}

	for (int i = 0; i < N; i++)
	{
		string sTemp;
		cin >> sTemp;
		arrB[i] += sTemp;
	}

	for (int i = 0; i < N-2; i++)
	{
		for (int j = 0; j < M-2; j++)
		{
			if (arrA[i][j] != arrB[i][j])
			{
				flip(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arrA[i][j] != arrB[i][j])
			{
				answer = -1;
				flag = true;
				break;
			}
		}

		if (flag)
		{
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}