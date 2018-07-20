#include <iostream>
#include <algorithm>
#include <vector>

#define LN 200

using namespace std;

int N, M;
vector<vector<int>> adj;

int path[LN + 1];
bool vst[LN + 1];

bool dfs(int n)
{
	if (vst[n])
	{
		return false;
	}
	vst[n] = true;

	for (int i : adj[n])
	{
		int v = i;

		// ���� ������ ���� ���� ��� || �ٸ� ���� ����� ���
		if (!path[v] || dfs(path[v]))
		{
			path[v] = n;
			return true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	adj.resize(N + 1);

	int s, a;
	for (int i = 1; i <= N; ++i)
	{
		cin >> s;
		for (int j = 0; j < s; ++j)
		{
			cin >> a;
			adj[i].push_back(a);
		}
	}

	// ��� �ҿ� ���Ͽ� DFS �ݺ�
	int sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		fill_n(vst, LN + 1, false);

		if (dfs(i))
		{
			++sum;
		}
	}

	cout << sum;

	return 0;
}