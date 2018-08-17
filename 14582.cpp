#include <iostream>

using namespace std;

int fst[9], snd[9];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; ++i)
	{
		cin >> fst[i];

	}
	for (int i = 0; i < 9; ++i)
	{
		cin >> snd[i];
	}

	int sum1 = 0, sum2 = 0;
	bool rev = false;
	for (int i = 0; i < 9; ++i)
	{
		sum1 += fst[i];	// i회 초 점수

		if (sum1 > sum2)
		{
			// 'i회 초 -> i회 말'과정에서 바뀌는 경우도 역전승
			rev = true;
		}

		sum2 += snd[i];	// i회 말 점수
	}

	cout << (rev ? "Yes" : "No");

	return 0;
}
