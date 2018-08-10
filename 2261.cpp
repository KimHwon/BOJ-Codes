#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int dist(pair<int, int> &p1, pair<int, int> &p2)
{
	return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}
bool compX(pair<int, int> &p1, pair<int, int> &p2)
{
	return p1.first < p2.first;
}
bool compY(pair<int, int> &p1, pair<int, int> &p2)
{
	return p1.second < p2.second;
}

/* x좌표로 정렬한 뒤, 분할정복으로 구함
* 경계 부분은 경계선을 기준으로 좌우로 min-dist 이내에 있는 점들만 비교
*/
int compare(vector<pair<int, int>>::iterator iter, int len)
{
	if (len == 2)
	{
		return dist(iter[0], iter[1]);
	}
	if (len == 3)
	{
		return min({ dist(iter[0], iter[1]), dist(iter[1], iter[2]), dist(iter[2], iter[0]) });
	}

	// 분할 정복
	int div = (iter[len / 2 - 1].first + iter[len / 2].first) / 2;
	int mindist = min(compare(iter, len / 2), compare(iter + len / 2, len - len / 2));

	// 경계값 비교
	vector<pair<int, int>> mids;
	for (int i = 0; i < len; i++)
	{
		int d = div - iter[i].first;
		if (d * d < mindist)
		{
			mids.push_back(iter[i]);
		}
	}

	sort(mids.begin(), mids.end(), compY);

	for (int i = 0; i < mids.size() - 1; i++)
	{
		for (int j = i + 1; j < mids.size() && mids[j].second - mids[i].second < mindist; j++)
		{
			mindist = min(mindist, dist(mids[i], mids[j]));
		}
	}

	return mindist;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<int, int>> points(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> points[i].first >> points[i].second;
	}

	sort(points.begin(), points.end(), compX);

	cout << compare(points.begin(), N);

	return 0;
}