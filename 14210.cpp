#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
string lists[50];
bool ena[32];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> lists[i];
	}

	string str;
	cin >> str;

	for (string s : lists)
	{
		auto f = s.find(str);
		if (f == 0 && s.size() > str.size())
		{
			ena[s[str.size()] - 62] = true;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (ena[i * 8 + j])
			{
				cout << (char)(i * 8 + j + 62);
			}
			else
			{
				cout << '*';
			}
		}
		cout << '\n';
	}

	return 0;
}
