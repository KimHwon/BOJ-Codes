#include <iostream>
#include <algorithm>

#define EXPLORED -1
#define UNVISITED 0
#define VISITED 1

using namespace std;

int N, Cnt;

int graph[100001];
int status[100001];

void dfs(int v)
{
	// Explored [v], but doesn't visited every neighbors
	status[v] = EXPLORED;

	int e = graph[v];

	if (status[e] == EXPLORED)
	{
		// Detected cycle

		// Count cycle members
		while (v != e)
		{
			++Cnt;
			e = graph[e];
		}
		++Cnt;
	}
	else if (status[e] == UNVISITED)
	{
		dfs(e);
	}

	// Now, visited every neighbors
	status[v] = VISITED;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--)
	{
		cin >> N;

		Cnt = 0;
		fill_n(status, N + 1, UNVISITED);

		for (int i = 1; i <= N; ++i)
		{
			cin >> graph[i];
		}

		for (int i = 1; i <= N; ++i)
		{
			// Try DFS every Nodes
			if (status[i] != VISITED)
			{
				dfs(i);
			}
		}

		cout << N - Cnt << '\n';
	}

	return 0;
}