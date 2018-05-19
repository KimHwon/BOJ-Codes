// C++11
#include <iostream>

#define FOR(i, n) for (int i = 0; i < n; ++i)
#define ull unsigned long long

using namespace std;
/*
	3^0 + 3^1 + 3^2 + 3^3 + ... + 3^n 꼴은 3진수 표기법이다
	3제곱의 합으로 이루어진 N번째 수 == 2진수의 각 비트를 3진수로 변환한 수
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ull n, dt = 1, r = 0;
	cin >> n;

	while (n > 0)
	{
		if (n % 2)	// 마지막 비트가 1이면 3^k를 사용(더함)
		{
			r += dt;
		}
		n >>= 1;	// shift (뒤로 1칸 당김)
		dt *= 3;	// dt=3^k / 자릿수를 올림
	}

	cout << r;

	return 0;
}
