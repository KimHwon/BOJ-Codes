// C++11
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int gcd(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<char> str1(N), str2(N * 2);

	for (int i = 0; i < N; ++i)
	{
		cin >> str1[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> str2[i];
		
		// 환형구조를 모두 탐색하기 위해 2번 반복
		str2[i + N] = str2[i];
	}

	// KMP Search
	vector<int> jmp(N);
	int eq = 0;
	for (int i = 1; i < N; ++i)
	{
		while (eq > 0 && str1[eq] != str1[i])
		{
			eq = jmp[eq - 1];
		}
		if (str1[eq] == str1[i])
		{
			++eq;
		}
		jmp[i] = eq;
	}

	int cnt = 0; eq = 0;
	for (int i = 0; i < N * 2 - 1; ++i)	// 포함배제원리 (size: 2N-1)
	{
		while (eq && str1[i] != str2[eq])
		{
			eq = jmp[eq - 1];
		}
		if (str1[i] == str2[eq])
		{
			++eq;

			if (eq == N)
			{
				++cnt;

				eq = jmp[eq - 1];
			}
		}
	}
	// 확률: cnt/N

	int div = gcd(cnt, N);
	cout << cnt / div << '/' << N / div;

	return 0;
}
