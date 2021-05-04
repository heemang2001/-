#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0; // 3 <= N <= 5000
	int nValue = -1;

	cin >> N; // N kg 배달함 , 3kg 5kg 봉지의 최소갯수 구하라 , 만들수없으면 -1출력

	int Fivekg_test = 0;

	if (N >= 5)
	{
		Fivekg_test = N / 5;
	}	

	for (int i = 0; i < Fivekg_test; i++)
	{
		int Threekg = 0;
		int Fivekg = N / 5 - i;			// 5kg 봉지갯수
		int Remain = N % 5 + (5 * i);	// 5kg로 나누고 남은 설탕 kg

		// 5kg봉지로 다 나눠지면 값 리턴
		if (Remain == 0)	
		{
			nValue = Fivekg;
			break;
		}

		// 5kg봉지로 나눈후 3kg봉지로 나눠지면 값 리턴
		if (Remain % 3 == 0)
		{
			Threekg = Remain / 3;
			nValue = Fivekg + Threekg;
			break;
		}
	}	

	// 5kg + 3Kg론 안나눠지면 3kg만으로 나눔
	// 나눠지면 그값리턴 안나눠지면 -1리턴
	if (nValue == -1 && N % 3 == 0)
	{
		int nTemp = N / 3;
		nValue = nTemp;
	}

	cout << nValue << '\n';
	
	return 0;
}