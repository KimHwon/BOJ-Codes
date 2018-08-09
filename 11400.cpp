#include <iostream>
#include <algorithm>
#include <vector>

#define LN 100001
#define UNVISITED -1

using namespace std;

int V, E;

vector<int> graph[LN];
int dfsIdx[LN], dfsMin[LN], dfsPar[LN];
int index, root, rootCnt;

vector<pair<int, int>> bridge;

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

			if (dfsMin[e] > dfsIdx[v])
			{
				bridge.push_back(make_pair(min(e, v), max(e, v)));
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
	fill_n(dfsIdx, LN, UNVISITED);

	for (int i = 1; i <= V; ++i)
	{
		if (dfsIdx[i] == UNVISITED)
		{
			root = i;
			rootCnt = 0;

			dfs(i);
		}
	}
	sort(bridge.begin(), bridge.end());

	cout << bridge.size() << '\n';
	for (auto p : bridge)
	{
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}