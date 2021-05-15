#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes)
{
	// 기본 카메라 1대
	int answer = 1;

	sort(routes.begin(), routes.end());

	// 처음 차가 나가는 부분
	int out = routes[0][1];

	for (int i = 1; i < routes.size(); i++)
	{
		// 현재 차가 나가는 부분보다 뒤에 차가 들어온다면
		if (out < routes[i][0])
		{
			// 카메라 설치
			answer++;

			// 나가는 부분 정정
			out = routes[i][1];
		}

		// 현재 차보다 뒤차가 먼저 나가면
		if (out >= routes[i][1])
		{
			// 나가는 부분을 뒷차로 수정
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