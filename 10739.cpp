#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int N, K;
int pos[100005];
ll dist[100005];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	int a;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		// pos[i] : 문 a를 여는 열쇠의 위치 (또는 열쇠를 사용하는 순서)
		pos[a - 1] = i;
	}

	// 처음 사용한 열쇠 ~ 1번째 문을 여는 열쇠까지 실패 횟수
	ll cnt = pos[0];

	for (int i = 1; i <= N; ++i)
	{
		// d : i번째 열쇠 ~ (i - 1)번째 열쇠까지 실패 횟수
		int d = pos[i - 1] - pos[(i - 2 + N) % N];
		if (d < 0)
		{
			d += N;
		}

		// dist[i] : i번째 문을 여는데까지 실패한 누적 횟수
		dist[i] = dist[i - 1] + d;
	}

	// dist[N] * (K / N) : (1~N번째 문을 여는 사이클)들의 합
	// dist[K % N] - dist[1] : (N~K번째 문을 여는 실패 횟수의 합) - (N->1로 오는 실패 횟수)
	cnt += (dist[N] * (K / N)) + (dist[K % N] - dist[1]);

	cout << cnt;

	return 0;
}
