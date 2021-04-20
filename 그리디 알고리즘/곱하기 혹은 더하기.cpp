#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;

	cin >> str;

	// ù ��° ���ڸ� ���ڷ� ������ ���� ����
	long long result = str[0] - '0';

	for (int i = 1; i < str.size(); i++)
	{
		// �� �� �߿��� �ϳ��� '0' Ȥ�� '1'�� ���, ���ϱ⺸�ٴ� ���ϱ� ����
		int num = str[i] - '0';

		if (num <= 1 || result <= 1)
		{
			result += num;
		}

		else
		{
			result *= num;
		}
	}

	cout << result << '\n';

	return 0;
}