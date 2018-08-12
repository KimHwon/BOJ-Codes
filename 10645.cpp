#include <iostream>
#include <algorithm>

#define LN 1000005

using namespace std;

int N, K;
int row[LN], col[LN];
int dgR[LN * 2], dgL[LN * 2];

// 행,열,오른쪽대각선,왼쪽대각선의 모든 선마다 버섯이 몇 개인지 셈

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	int x, y, tm = 1e9;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;

		++row[x];
		++col[y];
		++dgR[x - y + LN];
		++dgL[x + y];

		if (row[x] == K || col[y] == K || dgR[x - y + LN] == K || dgL[x + y] == K)
		{
			tm = min(tm, i + 1);
		}
	}

	if (tm == 1e9)
	{
		cout << -1;
	}
	else
	{
		cout << tm;
	}

	return 0;
}