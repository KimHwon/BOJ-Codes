// C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	vector<int> jmp(str2.size(), 0);
	vector<int> rslt;

	int eq = 0;
	for (int i = 1; i < str2.size(); ++i)
	{
		while (eq && str2[i] != str2[eq])
		{
			eq = jmp[eq - 1];
		}
		if (str2[i] == str2[eq])
		{
			++eq;
			jmp[i] = eq;
		}
	}

	int cnt = 0; eq = 0;
	for (int i = 0; i < str1.size(); ++i)
	{
		while (eq && str1[i] != str2[eq])
		{
			eq = jmp[eq - 1];
		}
		if (str1[i] == str2[eq])
		{
			++eq;

			if (eq == str2.size())
			{
				rslt.push_back(i - eq + 1);
				++cnt;

				eq = jmp[eq - 1];
			}
		}
	}

	cout << cnt << '\n';
	for (int i : rslt)
	{
		cout << i + 1 << '\n';
	}

	return 0;
}
