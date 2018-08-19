//C++11
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cost[1000][3];
int mincost[1000][3];

int paint(int n, int c)
{
	if (n == N) return 0;

	if (mincost[n][c])
	{
		return mincost[n][c];
	}

	mincost[n][c] = min(paint(n + 1, (c + 1) % 3), paint(n + 1, (c + 2) % 3)) + cost[n][c];
	return mincost[n][c];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> cost[i][j];
		}
	}

	cout << min(paint(0, 0), min(paint(0, 1), paint(0, 2))) << '\n';

	return 0;
}
