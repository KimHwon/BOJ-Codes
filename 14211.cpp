#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, Sum;
int bn[505], mem[505][50005];

int divs(int idx, int diff)
{
	// diff = abs(Kile - Pogi);

	// 절반을 넘게 분배하면, 불균등함
	if (diff > Sum / 2)
	{
		return -1e9;
	}

	int& dp = mem[idx][diff];
	if (dp != -1)
	{
		return dp;
	}

	// 종료 시점에 균등한지에 따라 반환
	if (idx == N)
	{
		return dp = (diff ? -1e9 : 0);
	}

	return dp = max({
		divs(idx + 1, diff),	// 버릴 때
		divs(idx + 1, diff + bn[idx]) + bn[idx],	// 많이 가진 쪽에게 더 줄 때
		divs(idx + 1, abs(diff - bn[idx])) + max(0, bn[idx] - diff)	// 적게 가진 쪽에게 줄 때
	});

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> bn[i];
		Sum += bn[i];
	}
	memset(mem, -1, sizeof mem);

	cout << (Sum - divs(0, 0));

	return 0;

}
