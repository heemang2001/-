#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N; // 과일 갯수
int L; // 스네이크버드 초기 길이
vector<int> vecFruit;

int main()
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecFruit.push_back(nTemp);
	}

	sort(vecFruit.begin(), vecFruit.end());

	for (int i = 0; i < vecFruit.size(); i++)
	{
		if (vecFruit[i] <= L)
		{
			L++;
		}
	}

	cout << L << '\n';

	return 0;
}