// C++11
#include <iostream>
#include <vector>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int format[4][4] = 		// 4x4칸 이하일 경우, 더 이상 재귀호출하는 대신 참조로 풀이
{
	{ 0, 1, 4, 5 },
	{ 2, 3, 6, 7 },
	{ 8, 9, 12, 13 },
	{ 10, 11, 14, 15 }
};
int sum, _x, _y;

void count(int x, int y, int sz)
{
	if (sz <= 4)
	{
		sum += format[_x % 4][_y % 4];
		return;
	}
	else if (sz == 1)
	{
		return;
	}

	if ((x <= _x && _x < x + (sz / 2)) && (y <= _y && _y < y + (sz / 2)))			// 목표값이 왼쪽위 영역에 있을 경우
	{
		count(x, y, sz / 2);
	}
	else if ((x + (sz / 2) <= _x && _x < x + sz) && (y <= _y && _y < y + (sz / 2)))		// 목표값이 오른쪽위 영역에 있을 경우
	{
		sum += (sz / 2) * (sz / 2);
		count(x + (sz / 2), y, sz / 2);
	}
	else if ((x <= _x && _x < x + (sz / 2)) && (y + (sz / 2) <= _y && _y < y + sz))		// 목표값이 왼쪽아래 영역에 있을 경우
	{
		sum += (sz / 2) * (sz / 2) * 2;
		count(x, y + (sz / 2), sz / 2);
	}
	else											// 목표값이 오른쪽아래 영역에 있을 경우
	{
		sum += (sz / 2) * (sz / 2) * 3;
		count(x + (sz / 2), y + (sz / 2), sz / 2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n >> _x >> _y;

	count(0, 0, 1 << n);

	cout << sum;

	return 0;
}
