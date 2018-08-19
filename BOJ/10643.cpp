#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int pizza[8];
	for (int i = 0; i < 8; ++i)
	{
		cin >> pizza[i];
	}

	int mx = 0;
	for (int i = 0; i < 8; ++i)
	{
		int s = 0;
		for (int j = 0; j < 4; ++j)
		{
			s += pizza[(i + j) % 8];
		}

		mx = max(mx, s);
	}

	cout << mx;

	return 0;
}