#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0; // 3 <= N <= 5000
	int nValue = -1;

	cin >> N; // N kg ����� , 3kg 5kg ������ �ּҰ��� ���϶� , ����������� -1���

	int Fivekg_test = 0;

	if (N >= 5)
	{
		Fivekg_test = N / 5;
	}	

	for (int i = 0; i < Fivekg_test; i++)
	{
		int Threekg = 0;
		int Fivekg = N / 5 - i;			// 5kg ��������
		int Remain = N % 5 + (5 * i);	// 5kg�� ������ ���� ���� kg

		// 5kg������ �� �������� �� ����
		if (Remain == 0)	
		{
			nValue = Fivekg;
			break;
		}

		// 5kg������ ������ 3kg������ �������� �� ����
		if (Remain % 3 == 0)
		{
			Threekg = Remain / 3;
			nValue = Fivekg + Threekg;
			break;
		}
	}	

	// 5kg + 3Kg�� �ȳ������� 3kg������ ����
	// �������� �װ����� �ȳ������� -1����
	if (nValue == -1 && N % 3 == 0)
	{
		int nTemp = N / 3;
		nValue = nTemp;
	}

	cout << nValue << '\n';
	
	return 0;
}