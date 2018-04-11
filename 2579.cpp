#include <iostream>

#define LN 300+1
#define MAX(a, b) (( (a) > (b) ) ? (a) : (b))

using namespace std;

int stair[LN];
int sum1[LN];
int sum2[LN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i)
	{
		cin >> stair[i];
	}

	sum1[1] = sum2[1] = stair[1];

	for (int i = 2; i <= t; ++i)
	{
		sum1[i] = sum2[i - 1] + stair[i];
		sum2[i] = MAX(sum1[i - 2], sum2[i - 2]) + stair[i];
	}

	cout << MAX(sum1[t], sum2[t]);

	return 0;
}
