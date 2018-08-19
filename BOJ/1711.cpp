#include <iostream>
#include <algorithm>
#include <vector>

#define ull unsigned long long
#define ll long long

using namespace std;

// 1500^3 = 3,375,000,000 이므로 전체탐색을 해도 충분한 시간이다.

int N;
vector<pair<ll, ll>> pnts;

ull dist(int a, int b)
{
	return (pnts[a].first - pnts[b].first) * (pnts[a].first - pnts[b].first) + (pnts[a].second - pnts[b].second) * (pnts[a].second - pnts[b].second);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	pnts.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> pnts[i].first >> pnts[i].second;
	}

	// 전체 탐색
	ll cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			for (int k = j + 1; k < N; ++k)
			{
				ull d[3], mx;
				d[0] = dist(i, j);
				d[1] = dist(j, k);
				d[2] = dist(k, i);

				mx = max({d[0], d[1], d[2]});
				if (mx * 2 == d[0] + d[1] + d[2])
				{
					++cnt;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}