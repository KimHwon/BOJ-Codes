#include <iostream>
#include <cstring>

using namespace std;

int cnt[41];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t, n;
	cin >> t;

	for (; t > 0; --t)
	{
		memset(cnt, 0, sizeof(cnt));
		cin >> n;

		if (n == 0)
		{
			cout << "1 0\n";
			continue;
		}

		cnt[1] = cnt[2] = 1;

		for (int i = 3; i <= n; ++i)
		{
			cnt[i] = cnt[i - 1] + cnt[i - 2];
		}

		cout << cnt[n - 1] << ' ' << cnt[n] << '\n';
	}

	return 0;
}
