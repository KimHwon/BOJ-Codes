// C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	int x;

	cin >> x >> str;

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
		}
	}

	// KMP pattern == 광고가 반복되어 나타난 부분
	// L - patternLength == 광고의 길이
	cout << str.size() - pi.back();

	return 0;
}
