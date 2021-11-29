#include <iostream>
#include <string>
using namespace std;

int t, bitlength, dist, ab, bb;
string a, b;

int main() {
	ios::sync_with_stdio(false);

	cin >> t;

	while (t--)
	{
		dist = ab = bb = 0;
		cin >> a >> b;

		bitlength = a.length();
		for (int i = 0; i < bitlength; i++)
		{
			if (a[i] != b[i])
			{
				// 차이나는 비트수
				dist++;
			}
				
			// 1의 비트 개수 (1)
			if (a[i] - '0')
			{
				ab++;
			}

			// 1의 비트 개수 (2)
			if (b[i] - '0')
			{
				bb++;
			}
		}

		cout << (dist + abs(bb - ab)) / 2 << '\n';
	}

	return 0;
}