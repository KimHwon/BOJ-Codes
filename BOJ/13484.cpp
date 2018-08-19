#include <iostream>

#define ull unsigned long long

using namespace std;

int X, N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> X >> N;

	ull sum = X;
	int a;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		sum += (X - a);
	}

	cout << sum;

	return 0;
}