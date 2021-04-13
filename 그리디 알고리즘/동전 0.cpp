#include <iostream>

using namespace std;

int Solution(int tN, int tK, int tarray[11]);

int main()
{
	int N;
	int K;
	int A[11] = {0};

	A[1] = 1;

	scanf_s("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
	{
		if ((i >= 2) && (1==(i%2)))
		{
			A[i] = 2 * A[i - 1];
		}

		else if ((i >= 2) && (0 == (i % 2)))
		{
			A[i] = 5 * A[i - 1];
		}

		printf("%d\n",A[i]);		
	}

	printf("%d",Solution(N, K, A));

	return 0;
}

int Solution(int tN, int tK, int tarray[11])
{
	int minValue = 0;
	int DivideValue = 0;

	for (int i = tN; i >= 1; i--)
	{
		if (tarray[i] < tK)
		{
			DivideValue = tK / tarray[i];
			tK = tK - (tarray[i] * DivideValue);
			minValue += DivideValue;
			DivideValue = 0;
		}		
	}

	return minValue;
}
