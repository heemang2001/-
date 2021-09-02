#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define MAX 10001

int N, M;
int answer;
int MinusIndex;
vector<int> vecBook;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecBook.push_back(nTemp);

		if (nTemp < 0)
		{
			MinusIndex++;
		}
	}

	sort(vecBook.begin(), vecBook.end());

	for (int i = N - 1; i >= MinusIndex; i -= M)
	{
		answer += (vecBook[i] * 2);
	}

	for (int i = 0; i < MinusIndex; i += M)
	{
		answer += abs(vecBook[i] * 2);
	}

	// ���� �հŸ��� ���߿�(0���� �ȵ��ƿ͵� ��)
	answer -= max(abs(vecBook.front()), abs(vecBook.back()));

	cout << answer << '\n';

	return 0;
}