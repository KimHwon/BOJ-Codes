#include <iostream>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, m, s;
	cin >> h >> m >> s >> N;

	long long tm = h * 3600 + m * 60 + s;	// sum to second
	int cmd, q;
	for (int i = 0; i < N; ++i)
	{
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			cin >> q;
			tm = (tm + q) % 86400;	// (current + query) % 24h
			break;
		case 2:
			cin >> q;
			tm = (tm - q) % 86400;	// (current - query) % 24h
			break;
		case 3:
			if (tm < 0)
			{
				tm += 86400;	// + 24h
			}
			printf("%lld %lld %lld\n", tm / 3600, (tm % 3600) / 60, tm % 60);
			break;
		}
	}

	return 0;
}
