// C++11
#include <iostream>
#include <cstring>

using namespace std;

int sum[12];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;

	for (; t > 0; --t)
	{
		memset(sum, 0, sizeof(sum));
		cin >> n;

		sum[1] = 1;
		sum[2] = 2;
		sum[3] = 4;
		for (int i = 4; i <= n; ++i)
		{
			sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
		}

		cout << sum[n] << '\n';
	}

	return 0;
}
