// C++11
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	int pttr;

	while (true)
	{
		cin >> str;
		if (str.front() == '.') break;

		pttr = 1;	// Find pattern length
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] != str[i % pttr])
			{
				pttr = i + 1;
			}
		}

		cout << str.size() / pttr << '\n';
	}

	return 0;
}
