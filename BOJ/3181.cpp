#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
string pass[10] = { "i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili" };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;

	cin >> str;
	cout << (char)(str[0] - 32);

	while (cin >> str)
	{
		if (find(pass, pass + 10, str) == pass + 10)
		{
			cout << (char)(str[0] - 32);
		}
	}

	return 0;
}