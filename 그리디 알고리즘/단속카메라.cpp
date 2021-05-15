#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
	// �⺻ ī�޶� 1��
	int answer = 1;

	sort(routes.begin(), routes.end());

	// ó�� ���� ������ �κ�
	int out = routes[0][1];

	for (int i = 1; i < routes.size(); i++)
	{
		// ���� ���� ������ �κк��� �ڿ� ���� ���´ٸ�
		if (out < routes[i][0])
		{
			// ī�޶� ��ġ
			answer++;

			// ������ �κ� ����
			out = routes[i][1];
		}

		// ���� ������ ������ ���� ������
		if (out >= routes[i][1])
		{
			// ������ �κ��� ������ ����
			out = routes[i][1];
		}
	}

	return answer;
}

int main()
{
	cout << solution({ { -20,15 }, { -14,-5 }, { -18,-13 }, { -5,-3 } }) << '\n'; // 2

	return 0;
}