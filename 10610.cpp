#include <iostream>
#include <string>

using namespace std;

int nums[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	long charsum = 0;
	for (char c : str)
	{
		++nums[c - '0'];

		charsum += c - '0';
	}

	// !(3의 배수 && 10의 배수)
	if (charsum % 3 || nums[0] == 0)
	{
		cout << -1;
		
		return 0;
	}

	// 큰 수부터 push_back
	string max = "";
	for (int i = 9; i >= 0; --i)
	{
		for (int j = 0; j < nums[i]; ++j)
		{
			max += i + '0';
		}
	}

	cout << max;

	return 0;
}
