#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<vector<int>> tree;
bool vst[500001];

int sum;

void dfs(int n, int cnt)
{
	vst[n] = true;

	for (int i : tree[n])
	{
		if (!vst[i])
		{
			dfs(i, cnt + 1);
		}
	}

	// leaf노드일 때, Root에서 leaf까지 거리를 sum에 더한다
	if (tree[n].size() == 1)
	{
		sum += cnt;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	tree.resize(N + 1);

	int a, b;
	for (int i = 0; i < N - 1; ++i)
	{
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, 0);

	// 각 leaf에서 root로 갈 때, 총 이동 횟수가 짝수면 이기고 홀수면 진다
	cout << ((sum % 2) ? "Yes" : "No");

	return 0;
}