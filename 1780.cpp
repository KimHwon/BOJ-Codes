// C++11
// 1992번 문제와 유사 --> 해당 문제 코드 참조
#include <iostream>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int paper[2187][2187];
int cnt[3];

void cut(int x, int y, int sz)
{
	if (sz == 1)
	{
		++cnt[paper[x][y] + 1];
		return;
	}

	int flag = paper[x][y];
	for (int i = x; i < x + sz; ++i)
	{
		for (int j = y; j < y + sz; ++j)
		{
			if (flag != paper[i][j])
			{
				cut(x, y, sz / 3);
				cut(x + (sz / 3), y, sz / 3);
				cut(x + (sz / 3) * 2, y, sz / 3);
				cut(x, y + (sz / 3), sz / 3);
				cut(x + (sz / 3), y + (sz / 3), sz / 3);
				cut(x + (sz / 3) * 2, y + (sz / 3), sz / 3);
				cut(x, y + (sz / 3) * 2, sz / 3);
				cut(x + (sz / 3), y + (sz / 3) * 2, sz / 3);
				cut(x + (sz / 3) * 2, y + (sz / 3) * 2, sz / 3);

				return;
			}
		}
	}

	++cnt[paper[x][y] + 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	FOR(i, n)
	{
		FOR(j, n)
		{
			cin >> paper[i][j];
		}
	}

	cut(0, 0, n);

	cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2];

	return 0;
}
