#include <iostream>
#include <algorithm>

using namespace std;

int N;
int que[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> que[i];
	}

	sort(que, que + N);
	// 빨리 처리하는 사람 먼저

	long long sum = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			sum += que[j];
		}
	}

	cout << sum;

	return 0;
}