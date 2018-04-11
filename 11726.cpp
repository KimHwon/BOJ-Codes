// C++11
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
		block[i] = (block[i - 1] + block[i - 2]) % 10007; // overflow가 일어나므로 각 계산마다 10007을 나눠 int영역 안으로 계산
	}

	cout << (block[n] % 10007); // overflow가 일어나므로 각 계산마다 10007을 나눠 int영역 안으로 계산

	return 0;
}
