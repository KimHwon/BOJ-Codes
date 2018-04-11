#include <iostream>

using namespace std;

int block[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	block[0] = block[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		block[i] = (block[i - 1] + block[i - 2]) % 10007;
	}

	cout << (block[n] % 10007);

	return 0;
}
