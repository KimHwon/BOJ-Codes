#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> tree;
int H, St;

int getMin(int n, int lb, int rb, int lt, int rt)
{
	if (lt > rb || rt < lb)
	{
		return (1 << 31) - 1;
	}
	if (lb >= lt && rb <= rt)
	{
		return tree[n];
	}

	return min(getMin(n * 2, lb, (lb + rb) / 2, lt, rt), getMin(n * 2 + 1, (lb + rb) / 2 + 1, rb, lt, rt));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (; (1 << H) < N; ++H);
	St = 1 << H;
	++H;

	tree.resize(1 << H, (1 << 31) - 1);

	for (int i = 0; i < N; ++i)
	{
		cin >> tree[St + i];
	}

	for (int i = St - 1; i > 0; --i)
	{
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		cout << getMin(1, 1, St, a, b) << '\n';
	}

	return 0;
}