#include <iostream>

using namespace std;

int count(int x, int y, int sz)
{
	if (sz == 1)
	{
		return 1;
	}

	if (x < (sz / 2))
	{
		if (y < (sz / 2))	// 왼쪽 위 1/4에 있을 경우
		{
			return count(x, y, sz / 2);
		}
		else			// 오른쪽 위 1/4에 있을 경우
		{
			return count(x, y - (sz / 2), sz / 2) + (sz * sz / 4);
		}
	}
	else
	{
		if (y < (sz / 2))	// 왼쪽 아래 1/4에 있을 경우
		{
			return count(x - (sz / 2), y, sz / 2) + (sz * sz / 4) * 2;
		}
		else			// 오른쪽 아래 1/4에 있을 경우
		{
			return count(x - (sz / 2), y - (sz / 2), sz / 2) + (sz * sz / 4) * 3;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;

	cout << count(x, y , 1 << n) - 1; // index가 0부터 시작하여 -1함

	return 0;
}
