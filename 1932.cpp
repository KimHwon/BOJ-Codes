#include <iostream>

#define FOR(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) (((a) > (b)) ? (a): (b))

using namespace std;

int tri[500][500];
int mem[500][500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	FOR(i, t)
	{
		FOR(j, i + 1)
		{
			cin >> tri[i][j];
		}
	}

	mem[0][0] = tri[0][0];
	for (int i = 1; i < t; ++i)
	{
		FOR(j ,i + 1)
		{
			mem[i][j] = tri[i][j] + MAX(mem[i - 1][j], mem[i - 1][j - 1]);
		}
	}

	int max = mem[t - 1][0];
	FOR(i, t)
	{
		max = MAX(max, mem[t - 1][i]);
	}
	cout << max;

	return 0;
}
