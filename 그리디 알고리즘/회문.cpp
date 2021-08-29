#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int T;

enum
{
	PALINDROME = 0,
	SEMI_PALINDROME,
	NOT_PALINDROME
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string s;
		cin >> s;

		int result = PALINDROME;

		for (int i = 0, j = s.length() - 1; i < j; i++, j--)
		{
			if (s[i] == s[j])
			{
				continue;
			}

			// ���� �ϳ��� �����ص� �Ӹ������ �ƴ� ���
			if (s[i + 1] != s[j] && s[i] != s[j - 1])
			{
				result = NOT_PALINDROME;

				break;
			}

			bool isPalindrome = false;

			// �ϳ� ������ �� �Ӹ�������� �Ǻ�
			for (int k = 0; k < 2 && isPalindrome == false; k++)
			{
				int start = i;
				int end = j;

				k == 0 ? start++ : end--;

				isPalindrome = true;

				for (int a = start, b = end; a < b; a++, b--)
				{
					if (s[a] != s[b])
					{
						isPalindrome = false;

						break;
					}
				}
			}

			result = isPalindrome ? SEMI_PALINDROME : NOT_PALINDROME;

			break;
		}

		cout << result << "\n";
	}

	return 0;
}

//// �ð��ʰ�
//bool IsPalindrome(string str);
//
//bool IsPseudoPalindrome(string str)
//{
//	for (int i = 0; i < str.size(); i++)
//	{
//		string sTemp = str;
//
//		sTemp.erase(sTemp.begin() + i);
//
//		if (IsPalindrome(sTemp))
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//bool IsPalindrome(string str)
//{
//	string sTemp = str;
//	string reverseStr = "";
//	reverse(str.begin(), str.end());
//	reverseStr = str;
//
//	if (sTemp == reverseStr)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//int main()
//{
//	cin >> T;
//
//	vector<string> vecString;
//	vector<int> vecAnswer;
//
//	for (int i = 0; i < T; i++)
//	{
//		string sTemp;
//		cin >> sTemp;
//		vecString.push_back(sTemp);
//	}
//
//	for (int i = 0; i < vecString.size(); i++)
//	{
//		// ���� ��ü�� ȸ���ΰ�?
//		if (IsPalindrome(vecString[i]))
//		{
//			vecAnswer.push_back(0);
//		}
//
//		// ����ȸ���ΰ�?
//		else if (IsPseudoPalindrome(vecString[i]))
//		{
//			vecAnswer.push_back(1);
//		}
//
//		else
//		{
//			vecAnswer.push_back(2);
//		}
//	}
//
//	for (int i = 0; i < vecAnswer.size(); i++)
//	{
//		cout << vecAnswer[i] << '\n';
//	}
//
//	return 0;
//}