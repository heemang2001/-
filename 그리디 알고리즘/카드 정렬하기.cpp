#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;

	// ���ĵ� ������ �Ѱ��� ������ ���� �ʿ� ����.
	if (N == 1)
	{
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < N; ++i)
	{
		int a;
		cin >> a;
		Q.push(a);
	}

	int ans = 0;

	// �ִ��� ���� �ֵ��� ���� ���´�.
	while (Q.size() > 1)
	{
		int a = Q.top();
		Q.pop();
		int b = Q.top();
		Q.pop();
		ans += a + b;
		Q.push(a + b);
	}

	cout << ans << '\n';

	return 0;
}