// C++11
#include <iostream>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, sum, div;
	cin >> n;
  
	FOR(i, n)     // 0부터 n까지 전부 계산해 봄
	{
		sum = div = i;
		while (div > 0)
		{
			sum += div % 10;
			div /= 10;
		}

		if (sum == n)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
}
