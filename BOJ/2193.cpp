//C++11
#include <iostream>

#define ull unsigned long long

using namespace std;

int N;
ull sum[91] = { 0, 1 };

// #1) 직접 n번째 항을 구해보면 피보나치수열이라는 것을 알 수있다.
/* #2) 일반화
	기저조건 [1], [2]를 제외
	모든 이친수는 1로 시작하므로 다음에는 항상 0이 나온다. -> 10xxxx꼴로 고정
	i) 101xxx일 경우
		다음에 0이 나와야 하므로 [n-2]인 경우와 같다 : 10"10xx"
	ii) 100xxx일 경우
		다음에 0 또는 1이 나와야 하므로 [n-1]인 경우와 같다 : 10"0xxx"
	따라서 [n] = [n-1] + [n-2]
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 2; i <= N; ++i)
	{
		sum[i] = sum[i - 1] + sum[i - 2];
	}

	cout << sum[N];

	return 0;
}
