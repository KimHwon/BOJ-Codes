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
		int l = n - (i * 5);
		if (l % 3 == 0)
		{
			r = i + (l / 3);
			r0 = (r < r0) ? r : r0;
		}
	}

	if (r0 == 999999)
		cout << -1;
	else
		cout << r0;

	return 0;
}
