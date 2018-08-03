#include <iostream>
#include <algorithm>

#define ull unsigned long long

using namespace std;

ull H, W;

/* i) H = 1
 *		못 움직임
 * ii) H = 2
 *		min(3, (w - 1) / 2) + 1
 *		URR 움직임이나 DRR 움직임만 가능하므로 4회 이상 움직일 수 없음
 * iii) H >= 3
 *		H에 의한 제약이 없다 - W로 결정됨
 *		j) W >= 7
 *			cycle이 가능할 때, W-3 회 움직인다 (귀납적 해석)
 *		jj) W < 7
 *			4가지 움직임을 사용하는 cycle이 불가능 할 때, 4회 이상 움직일 수 없음
 */

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;

	if (H == 1)
	{
		cout << 1;
	}
	else if (H == 2)
	{
		cout << min((ull)3, (W - 1) / 2) + 1;
	}
	else
	{
		if (W >= 7)
		{
			cout << W - 2;
		}
		else
		{
			cout << min((ull)3, W - 1) + 1;
		}
	}

	return 0;
}