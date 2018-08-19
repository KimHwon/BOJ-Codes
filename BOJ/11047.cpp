#include <iostream>

using namespace std;

int N, K;
int coin[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> coin[i];
	}

	int cnt = 0, i = N - 1;
	while (K > 0)
	{
		for (; i >= 0; --i)
		{
			if (K >= coin[i])
			{
				K -= coin[i];
				++cnt;

				break;
			}
		}
	}

	cout << cnt;

	return 0;
}