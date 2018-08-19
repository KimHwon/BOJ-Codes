//C++11
#include <iostream>
#include <algorithm>

#define ull unsigned long long

using namespace std;

int N, M;
ull com[31][31];

// 파스칼의 삼각형
ull comb(int n, int r)
{
	if (n == r || r == 0)
	{
		return 1;
	}

	if (com[n][r])
	{
		return com[n][r];
	}

	com[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
	return com[n][r];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		cin >> N >> M;
		cout << comb(M, N) << '\n';
	}

	return 0;
}
