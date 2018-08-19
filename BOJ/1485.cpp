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
int inp(Vector& v1, Vector& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		pair<int, int> ptn[4];
		for (int i = 0; i < 4; ++i)
		{
			cin >> ptn[i].first >> ptn[i].second;
		}
		// 볼록다각형이 되도록 점의 위치를 정렬해 선택한다
		sort(ptn, ptn + 4);

		Vector vec[4];
		vec[0] = Vector(ptn[1], ptn[0]);
		vec[1] = Vector(ptn[2], ptn[0]);
		vec[2] = Vector(ptn[3], ptn[1]);
		vec[3] = Vector(ptn[3], ptn[2]);

		// 두 변의 내적이 0이고, 직각인 두 벡터의 크기가 같으면 정사각형
		if (inp(vec[0], vec[1]) == 0 && inp(vec[0], vec[2]) == 0 && inp(vec[0], vec[3]))
		{
			if (vec[0].sz2 == vec[1].sz2)
			{
				cout << "1\n";
				continue;
			}
		}
		else if (inp(vec[0], vec[1]) == 0 && inp(vec[0], vec[3]) == 0 && inp(vec[0], vec[2]))
		{
			if (vec[0].sz2 == vec[1].sz2)
			{
				cout << "1\n";
				continue;
			}
		}
		else if (inp(vec[0], vec[2]) == 0 && inp(vec[0], vec[3]) == 0 && inp(vec[0], vec[1]))
		{
			if (vec[0].sz2 == vec[2].sz2)
			{
				cout << "1\n";
				continue;
			}
		}

		cout << "0\n";
	}

	return 0;
}