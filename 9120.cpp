#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--)
	{
		string str, pttn;
		cin >> pttn >> str;

		vector<int> pi(pttn.size(), 0);
		int eq = 0;
		for (int i = 1; i < pttn.size(); ++i)
		{
			while (eq && pttn[i] != pttn[eq])
			{
				eq = pi[eq - 1];
			}
			if (pttn[i] == pttn[eq])
			{
				++eq;
				pi[i] = eq;
			}
		}

		int cnt = 0; eq = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			while (eq && str[i] != pttn[eq])
			{
				eq = pi[eq - 1];
			}
			if (str[i] == pttn[eq])
			{
				++eq;

				if (eq == pttn.size())
				{
					++cnt;

					eq = pi[eq - 1];
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}