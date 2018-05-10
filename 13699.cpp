// C++11
#include <iostream>

#define ull unsigned long long

using namespace std;

ull tarr[36];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	tarr[0] = 1;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			tarr[i] += (tarr[j] * tarr[i - j - 1]);
		}
	}

	cout << tarr[n];

	return 0;
}
