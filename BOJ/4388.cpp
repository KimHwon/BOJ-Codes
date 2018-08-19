#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	while (true)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
		{
			return 0;
		}

		int cnt = 0, c = 0;
		while (a || b)
		{
			c = (a % 10 + b % 10 + c) / 10;
			if (c)	// sum >= 10
			{
				++cnt;
			}

			a /= 10;
			b /= 10;
		}
		cout << cnt << '\n';
	}

	return 0;
}