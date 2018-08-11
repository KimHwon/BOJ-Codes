#include <iostream>
#include <algorithm>

using namespace std;

struct Vector
{
	int x, y;
	long sz2;

	Vector() {}
	Vector(pair<int, int>& p1, pair<int, int>& p2)
	{
		x = p1.first - p2.first;
		y = p1.second - p2.second;
		sz2 = x * x + y * y;
	}
};

int outPdt(Vector& v1, Vector& v2)
{
	return (v1.x * v2.y - v2.x * v1.y);
}

int N;
pair<long long, long long> ptn[10000];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> ptn[i].first >> ptn[i].second;
	}

	// 신발끈 공식
	long long area = 0;
	for (int i = 0; i < N; ++i)
	{
		area += ptn[i].first * ptn[(i + 1) % N].second - ptn[i].second * ptn[(i + 1) % N].first;
	}

	printf("%.1lf", (double)abs(area) / 2.0);

	return 0;
}