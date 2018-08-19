#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, M, K;
vector<long long> tree;

long long sum(int n, int lb, int rb, int lt, int rt)
{
	if (lt > rb || rt < lb)
	{
		return 0;
	}
	if (lb >= lt && rb <= rt)
	{
		return tree[n];
	}

	return sum(n * 2, lb, (lb + rb) / 2, lt, rt) + sum(n * 2 + 1, (lb + rb) / 2 + 1, rb, lt, rt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	int h = (int)log2(N) + 2;
	int st = (1 << h) / 2;

	tree.resize(1 << h, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> tree[st + i];
	}
	for (int i = st - 1; i > 0; --i)
	{
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	int a, b, c;
	for (int t = 0; t < M + K; ++t)
	{
		cin >> a >> b >> c;

		if (a == 1)
		{
			int i = st + b - 1;
			tree[i] = c;

			while (i > 0)
			{
				i /= 2;
				tree[i] = tree[i * 2] + tree[i * 2 + 1];
			}
		}
		else
		{
			cout << sum(1, 1, st, b, c) << '\n';
		}
	}

	return 0;
}