#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char ucpc[] = "UCPC";

	string str;
	getline(cin, str);

	int i = 0;
	for (char c : str)
	{
		if (c == ucpc[i])
		{
			// if match, compare next char
			++i;
		}
	}

	// chars match 4 times
	cout << ((i >= 4) ? "I love UCPC" : "I hate UCPC");

	return 0;
}