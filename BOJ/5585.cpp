#include <iostream>

using namespace std;

int K;
int coin[6] = { 1, 5, 10, 50, 100, 500 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	K = 1000 - K;

	int cnt = 0, i = 5;
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