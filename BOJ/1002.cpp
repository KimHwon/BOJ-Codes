#include <iostream>
#include <cmath>

using namespace std;

// 두 원의 교점에 대한 문제

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		int x1, y1, r1;
		int x2, y2, r2;

		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;

		double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
			{
				cout << "-1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
		else
		{
			if ((r1 + r2) > d && abs(r1 - r2) < d)
			{
				cout << "2\n";
			}
			else if ((r1 + r2) == d || abs(r1 - r2) == d)
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}
	}

	return 0;
}