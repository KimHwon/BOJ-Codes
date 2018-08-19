#include <iostream>

using namespace std;

int N, K;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		cin >> N >> K;

		int cnt = 0, a;
		for (int i = 0; i < N; ++i)
		{
			cin >> a;
			cnt += a / K;
		}

		cout << cnt << '\n';
	}

	return 0;
}
