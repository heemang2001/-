#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// �ְ��� ���� == 1�޷��� ������ �ִ밡 �Ǵ� ����

int main()
{
	int answer = 0;
	int N; // ���� ����
	int A; // ���찡��
	int B; // ���ΰ���
	int C; // ���� Į�θ�

	cin >> N;
	cin >> A >> B;
	cin >> C;

	vector<int> vecToppingCal(N); // ���� Į�θ�

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecToppingCal[i] = nTemp;
	}

	sort(vecToppingCal.begin(), vecToppingCal.end(), greater<int>());

	int fTemp = C / A; // Į�θ� / ����
	answer = fTemp;

	for (int i = 0; i < vecToppingCal.size(); i++)
	{
		int nTemp = 0;

		if (i == 0)
		{
			nTemp = vecToppingCal[i];
		}

		else if(i >= 1)
		{
			for (int j = 0; j <= i; j++)
			{
				nTemp += vecToppingCal[j];
			}
		}

		fTemp = (C + nTemp) / (A + (B * (i + 1)));
		answer = max(answer, fTemp);
	}

	cout << answer << '\n';

	return 0;
}