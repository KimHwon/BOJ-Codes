#include <iostream>
#include <cstdlib>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		cin >> N;
		if (!N)
		{
			return 0;
		}

		int a, lst = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> a;

			if (lst != a)
			{
				cout << a << ' ';
				lst = a;
			}
		}

		cout << "$\n";
	}

	return 0;
}