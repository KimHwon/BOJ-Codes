#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int min = 0;
	string str, numStr = "";

	cin >> str;

	bool minus = false;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (minus)
			{
				min -= stoi(numStr);
			}
			else
			{

				min += stoi(numStr);
			}
			numStr = "";

			if (str[i] == '-')
			{
				minus = true;
				// Save minus flag to calculate next cycle
			}
		}
		else
		{
			// number charactors
			numStr += str[i];
		}
	}

	cout << min;

	return 0;
}