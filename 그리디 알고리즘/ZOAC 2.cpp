#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

string StrInput;
int Answer;

int main()
{
	cin >> StrInput;

	char curAlpha = 'A';

	for (int i = 0; i < StrInput.size(); i++)
	{
		int Lenth = min(abs(StrInput[i] - curAlpha), 26 - abs(StrInput[i] - curAlpha));
		Answer += Lenth;
		curAlpha = StrInput[i];
	}

	cout << Answer << '\n';

	return 0;
}