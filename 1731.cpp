#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	ll smp[3];

	for (int i = 0; i < 3; ++i)
	{
		cin >> smp[i];
	}

	ll last = smp[2];
	if (smp[0] + smp[2] == smp[1] + smp[1])
	{
		ll d = smp[1] - smp[0];

		for (int i = 0; i < N - 3; ++i)
		{
			cin >> last;
		}

		cout << last + d;
	}
	else
	{
		// 등비 수열
		ll r = smp[1] / smp[0];

		for (int i = 0; i < N - 3; ++i)
		{
			cin >> last;
		}

		cout << last * r;
	}

	return 0;
}