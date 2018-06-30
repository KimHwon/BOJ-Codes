// C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// KMP에서는 prefix가 문자열의 시작점으로 고정되지만,
// 문제의 조건에서는 prefix의 제한이 없으므로 모든 문자를 prefix로 할 때 비교한다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	int mx = 0;
	while (!str.empty())
	{
		vector<int> pi(str.size(), 0);

		int eq = 0;
		for (int i = 1; i < str.size(); ++i)
		{
			while (eq && str[i] != str[eq])
			{
				eq = pi[eq - 1];
			}
			if (str[i] == str[eq])
			{
				++eq;
				pi[i] = eq;

				if (mx < eq)
				{
					mx = eq;
				}
			}
		}

		// 맨 앞의 문자를 지우고 다시 KMP를 한다
		str.erase(str.begin());
	}

	cout << mx;

	return 0;
}
