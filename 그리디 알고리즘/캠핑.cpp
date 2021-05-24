#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nCase = 1;
vector<int> vecAnswer;

int solution(int L, int P, int V)
{
	int answer = 0;

	while (1)
	{
		if (V >= P)
		{
			answer = answer + L;
			V = V - P;
		}
		
		else
		{
			answer = answer + min(L,V);
			break;
		}
	}
	
	nCase++;
	return answer;
}

int main()
{
	while (1)
	{
		int L, P, V;

		cin >> L >> P >> V;		

		if (L == 0 && P == 0 && V == 0)
		{
			break;
		}

		vecAnswer.push_back(solution(L, P, V));		
	}

	for (int i = 1; i <= vecAnswer.size(); i++)
	{
		cout << "Case " << i << ": " << vecAnswer[i - 1] << '\n';
	}

	return 0;
}