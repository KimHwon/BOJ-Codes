#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> resv[100000];

bool comp(pair<int, int> a, pair<int, int> b)
{
	return (a.second < b.second) || (a.second == b.second && a.first < b.first);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> resv[i].first >> resv[i].second;
	}

	// sort by end time
	sort(resv, resv + N, comp);

	int ed = 0, cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		// if start new schedule
		if (resv[i].first >= ed)
		{
			ed = resv[i].second;
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}