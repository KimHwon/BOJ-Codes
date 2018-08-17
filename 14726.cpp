#include <iostream>
#include <string>

#define INT(c) ((c) - '0')

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		string str;
		cin >> str;

		long sum = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (i % 2)
			{
				sum += INT(str[i]);
			}
			else
			{
				int n = INT(str[i]) * 2;
				sum += (n % 10) + (n / 10);
			}
		}

		cout << ((sum % 10) ? "F\n" : "T\n");
	}

	return 0;
}
