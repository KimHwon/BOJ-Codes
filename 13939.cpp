#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int _x; cin >> _x;

	string str;
	long sum = 0;
	while (cin >> str)
	{
		bool ed = (str.back() == '.') || (str.back() == '!') || (str.back() == '?');

		if ('A' <= str[0] && str[0] <= 'Z')	// first char is uppercase
		{
			bool name = true;

			int sz = (ed) ? (str.size() - 1) : (str.size());	// ignore punctuation mark
			for (int i = 1; i < sz; ++i)
			{
				if ('a' > str[i] || str[i] > 'z')
				{
					name = false;
				}
			}

			if (name)
			{
				++sum;
			}
		}

		if (ed)
		{
			cout << sum << '\n';
			sum = 0;
		}
	}

	return 0;
}
