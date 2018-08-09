#include <iostream>
#include <algorithm>
#include <vector>

#define UNVISITED -1

using namespace std;

int V, E;

vector<int> graph[10001];
int dfsIdx[10001], dfsMin[10001], dfsPar[10001];
int index, root, rootCnt;

bool point[10001];

void dfs(int v)
{
	dfsMin[v] = dfsIdx[v] = index;
	++index;

	for (auto& e : graph[v])
	{
		if (dfsIdx[e] == UNVISITED)
		{
			dfsPar[e] = v;
			if (v == root)
			{
				++rootCnt;
			}

			dfs(e);

			if (dfsMin[e] >= dfsIdx[v])
			{
				point[v] = true;
			}

			dfsMin[v] = min(dfsMin[v], dfsMin[e]);
		}
		else if (e != dfsPar[v])
		{
			dfsMin[v] = min(dfsMin[v], dfsMin[e]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;

	int a, b;
	for (int i = 0; i < E; ++i)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	fill_n(dfsIdx, 10001, UNVISITED);

	for (int i = 1; i <= V; ++i)
	{
		if (dfsIdx[i] == UNVISITED)
		{
			root = i;
			rootCnt = 0;

			dfs(i);

			point[i] = rootCnt > 1;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= V; ++i)
	{
		if (point[i])
		{
			++cnt;
		}
	}
	cout << cnt << '\n';
	for (int i = 1; i <= V; ++i)
	{
		if (point[i])
		{
			cout << i << ' ';
		}
	}

	return 0;
}