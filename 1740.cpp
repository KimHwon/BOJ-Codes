// C++11
#include <iostream>

#define FOR(i, n) for (int i = 0; i < n; ++i)
#define ull unsigned long long

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ull n, dt = 1, r = 0;
	cin >> n;

	while (n > 0)
	{
		if (n % 2)
		{
			r += dt;
		}
		n >>= 1;
		dt *= 3;
	}

	cout << r;

	return 0;
}
