#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M, N, K;
vector<int> arr;

// "M���� �׷�, �� �׷��� ���Ҵ� K�� ����"�� ������ ������ �Ѵ�.
// �� �׷��� ���� ū ���Ұ� ���� ������ �ǰ�, �׷� ���� ���ҵ��� ���� ������ �ȴ�.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	//		M-1+k		<=		N		<=		M*K
	// K�� + (M-1)�׷�*1��					M�׷�*K��
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
		// ������ M-1���� �׷����� �ɰ���
		vector<int> len(M - 1, (N - K) / (M - 1));
		for (int i = 0; i < (N - K) % (M - 1); ++i)
		{
			// �������� �� �׷�鿡 �й���
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