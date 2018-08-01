#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M, N, K;
vector<int> arr;

// "M개의 그룹, 각 그룹의 원소는 K개 이하"인 수열을 만들어야 한다.
// 각 그룹의 가장 큰 원소가 증가 수열이 되고, 그룹 내의 원소들이 감소 수열이 된다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	//		M-1+k		<=		N		<=		M*K
	// K개 + (M-1)그룹*1개					M그룹*K개
	if (M - 1 + K > N || N > M * K)
	{
		cout << -1;

		return 0;
	}

	for (int i = 1; i <= N; ++i)
	{
		arr.push_back(i);
	}

	reverse(arr.begin(), arr.begin() + K);

	if (M - 1 > 0)
	{
		// 적절히 M-1개의 그룹으로 쪼갠다
		vector<int> len(M - 1, (N - K) / (M - 1));
		for (int i = 0; i < (N - K) % (M - 1); ++i)
		{
			// 나머지는 각 그룹들에 분배함
			++len[i];
		}

		auto offset = arr.begin() + K;
		for (int i = 0; i < M - 1; i++)
		{
			reverse(offset, offset + len[i]);

			offset += len[i];
		}
	}

	for (int i : arr)
	{
		cout << i << ' ';
	}

	return 0;
}