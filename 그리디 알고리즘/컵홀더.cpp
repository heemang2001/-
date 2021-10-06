#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N;
int Answer;

void solution(string sTemp)
{
	bool bLL = false;

	for (int i = 0; i < N; i++)
	{
		if (sTemp[i] == 'S')
		{
			Answer++;			
		}

		else if(sTemp[i] == 'L' && sTemp[i + 1] == 'L')
		{
			i++;

			if (!bLL)
			{
				Answer += 2;
				bLL = true;
			}

			else if(bLL)
			{
				Answer++;				
			}	
		}
	}
}

int main()
{
	cin >> N;

	string sTemp;

	cin >> sTemp;

	solution(sTemp);

	cout << Answer << '\n';

	return 0;
}