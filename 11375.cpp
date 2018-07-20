#include <iostream>
#include <algorithm>
#include <vector>

#define LN 1000*2

using namespace std;

int N, M;
bool vst[LN + 2];

struct Edge
{
	int next, cap, rev;
};
vector<Edge> adj[LN + 2];

void makeEdge(int u, int v, int cap)
{
	int rev_uv = adj[v].size();		// u.reverse = v.last
	int rev_vu = adj[u].size();		// v.reverse = u.last

	adj[u].push_back({ v, cap, rev_uv });
	adj[v].push_back({ u, 0, rev_vu });
}

// Find augmenting path
int dfs(int v, int s, int f)
{
	if (v == s) return f;

	vst[v] = true;
	for (auto &e : adj[v])
	{
		if (!vst[e.next] && e.cap > 0)
		{
			int d = dfs(e.next, s, min(f, e.cap));

			if (d > 0)
			{
				e.cap -= d;
				adj[e.next][e.rev].cap += d;

				return d;
			}
		}
	}

	return 0;
}
// Flowing while
int maxFlow(int s, int t)
{
	int flow = 0;

	while (true)
	{
		fill_n(vst, LN + 2, false);

		int f = dfs(s, t, 1e9);

		if (f == 0) return flow;

		flow += f;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	// 0 -> i : 시작점 노드 -> 이분매칭을 할 왼쪽 노드
	for (int i = 1; i <= N; ++i)
	{
		makeEdge(0, i, 1);
	}
	// N+i -> N+M+i : 이분매칭을 할 오른쪽 노드 -> 끝점 노드
	for (int i = 1; i <= M; ++i)
	{
		makeEdge(N + i, N + M + 1, 1);
	}
	
	// i -> N+a : 이분매칭을 할 왼쪽 노드 -> 오른쪽 노드
	int s, a;
	for (int i = 1; i <= N; ++i)
	{
		cin >> s;
		for (int j = 0; j < s; ++j)
		{
			cin >> a;

			makeEdge(i, N + a, 1);
		}
	}

	cout << maxFlow(0, M + N + 1);

	return 0;
}