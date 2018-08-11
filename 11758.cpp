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

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	pair<int, int> p[3];
	for (int i = 0; i < 3; ++i)
	{
		cin >> p[i].first >> p[i].second;
	}

	Vector v1(p[1], p[0]), v2(p[2], p[1]);

	// get Outer-product
	int op = outPdt(v1, v2);

	if (op > 0)
	{
		// (outer-product > 0) == counter-clockwise
		cout << 1;
	}
	else if (op < 0)
	{
		// (outer-product < 0) == clockwise
		cout << -1;
	}
	else
	{
		// (outer-product == 0) == straight
		cout << 0;
	}

	return 0;
}