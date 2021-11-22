#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int A, B, N;
int Answer;
int arrShortCut[5];

int main()
{
	cin >> A >> B;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> arrShortCut[i];
	}

	int differ = abs(A - B);
	if (differ == 0)
	{
		cout << Answer << '\n';
		return 0;
	}

	bool bShortCut = false;
	for (int i = 0; i < N; i++)
	{
		int new_differ = abs(B - arrShortCut[i]);

		if (new_differ == 0)
		{			
			cout << 1 << '\n';
			return 0;
		}

		else if(differ > new_differ)
		{
			bShortCut = true;
			differ = new_differ;			
		}
	}

	if (bShortCut)
	{
		Answer++;
	}

	Answer += differ;

	cout << Answer << '\n';

	return 0;
}