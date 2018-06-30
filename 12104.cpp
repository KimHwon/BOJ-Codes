// C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	// 순환구조를 모두 탐색하기 위해 2번 반복
	str2 += str2;

	// xor연산 결과가 0인 경우는 두 문자열이 일치 할 때이다
	// KMP Search
	vector<int> pi(str1.size(), 0);
	int eq = 0;
	for (int i = 1; i < str1.size(); ++i)
	{
		while (eq && str1[i] != str1[eq])
		{
			eq = pi[eq - 1];
		}
		if (str1[i] == str1[eq])
		{
			++eq;
			pi[i] = eq;
		}
	}

	int cnt = 0;  eq = 0;
	for (int i = 0; i < str2.size() - 1; ++i)	// 포함배제원리
	{
		while (eq && str2[i] != str1[eq])
		{
			eq = pi[eq - 1];
		}
		if (str2[i] == str1[eq])
		{
			++eq;

			if (eq == str1.size())
			{
				++cnt;

				eq = pi[eq - 1];
			}
		}
	}

	cout << cnt;

	return 0;
}
