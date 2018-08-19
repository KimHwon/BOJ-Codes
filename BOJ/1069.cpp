#include <iostream>
#include <algorithm>
#include <cmath>

#define ull unsigned long long
#define ld long double

using namespace std;

ull X, Y, D, T;

/* 움직임을 조합해서 도착시키는 방법을 생각하는 것이 아니라,
 * 목적지까지 도착할 때 어떤 움직임으로 가야 하는지 생각해야 한다.
 */

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> X >> Y >> D >> T;

	ld d = sqrtl(X * X + Y * Y);
	ull mv = d / D;
	ld left = d - mv * D;

	// i) 걸어서만 갈 때 (tm = d * 1)
	ld tm = d;

	// ii) 최대한 뛴 뒤, 남은 거리를 걸을 때
	tm = min(tm, (mv * T) + left);

	// iii) 1번 더 뛸 때
	if (mv > 0)
	{
		/* 일직선으로 1번 더 뛴다면 당연히 목적지를 넘어가겠지만,
		 * 방향을 바꾸면서 뛰면, 거리를 조절 할 수 있다.
		*/
		tm = min(tm, (ld)(mv + 1) * T);
	}
	// iv) mv가 1미만이면 (iii)와 같은 움직임을 할 수 없으므로, 케이스를 세분한다
	else
	{
		// iv-1) 1번 뛰고, 남은 거리를 걸음 (tm = 1 * T + (D - left) * 1)
		tm = min(tm, T + (D - left));

		if (d < D)
		{
			// iv-2) (iii)와 동일
			tm = min(tm, (ld)T * 2);
		}
	}

	printf("%.10Lf\n", tm);

	return 0;
}