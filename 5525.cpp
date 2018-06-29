// C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, x;
	string str, pttn = "I";

	cin >> N >> x >> str;

	for (int i = 0; i < N; ++i)
	{
		pttn.push_back('O');
		pttn.push_back('I');
	}

	vector<int> jmp(pttn.size(), 0);

	int eq = 0;
	for (int i = 1; i < pttn.size(); ++i)
	{
		while (eq && pttn[i] != pttn[eq])
		{
			eq = jmp[eq - 1];
		}
		if (pttn[i] == pttn[eq])
		{
			++eq;
			jmp[i] = eq;
		}
	}

	int cnt = 0; eq = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		while (eq && str[i] != pttn[eq])
		{
			eq = jmp[eq - 1];
		}
		if (str[i] == pttn[eq])
		{
			++eq;

			if (eq == pttn.size())
			{
				++cnt;

				eq = jmp[eq - 1];
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}
