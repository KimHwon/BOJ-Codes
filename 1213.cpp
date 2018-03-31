// C++11
#include <iostream>
#include <cstring>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int lib[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char name[51], pel[51];
	cin >> name;

	for (int i = 0; name[i]; ++i)
	{
		++lib[name[i] - 'A'];
	}

	int len = strlen(name);
	bool canCenter = (len % 2) ? true : false;
	char center;

	int iter = 0;
	FOR(j, 26)
	{
		if (lib[j] == 0)
		{
			continue;
		}
		else if (lib[j] % 2 == 0)
		{
			FOR(k, lib[j] / 2)
			{
				pel[iter] = j + 'A';
				pel[len - iter - 1] = j + 'A';
				++iter;
			}
		}
		else if (canCenter)
		{
			canCenter = false;
			center = j + 'A';
			FOR(k, lib[j] / 2)
			{
				pel[iter] = j + 'A';
				pel[len - iter - 1] = j + 'A';
				++iter;
			}
		}
		else
		{
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}

	if (len % 2) pel[len / 2] = center;
	pel[len] = '\0';

	cout << pel;

	return 0;
}
