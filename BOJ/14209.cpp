#include <iostream>
#include <string>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	long long sum = 0;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		for (char c : str)
		{
			switch (c)
			{
			case 'A': sum += 4; break;
			case 'K': sum += 3; break;
			case 'Q': sum += 2; break;
			case 'J': ++sum; break;
			}
		}
	}

	cout << sum;

	return 0;
}
