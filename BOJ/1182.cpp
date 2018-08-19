// C++11
#include <iostream>
#include <cmath>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int arr[20], n, s, cnt = 0, sum;
	cin >> n >> s;

	FOR(i, n)
	{
		cin >> arr[i];
	}
  // 부분집합에 사용할 원소들을 이진수의 0과 1로 결정 (각 비트를 Boolean배열처럼 사용)
	int binLim = (1 << n), b;   // 1<<n == 2^n 
	for (int i = 1; i < binLim; ++i)
	{
		sum = 0;
		b = i;
		FOR(j, n)
		{
			sum += (b % 2) * arr[j];  // 마지막 비트가 1이면 부분집합에 포함
			b >>= 1;    // shift (1비트 뒤로 당김)
		}

		if (sum == s)
		{
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}
