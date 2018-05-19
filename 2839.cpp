// C++11
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, l, r, r0 = 999999;
	cin >> n;

	for (int i = 0; i * 5 <= n; i++)
	{
		int l = n - (i * 5);	// 5의 배수로 한 번 나누고
		if (l % 3 == 0)		// 3의 배수로 나눠지는지 확인
		{
			r = i + (l / 3);
			r0 = (r < r0) ? r : r0;	// r0 : 가장 적은 수의 봉지 수
		}
	}

	if (r0 == 999999)
		cout << -1;
	else
		cout << r0;

	return 0;
}
