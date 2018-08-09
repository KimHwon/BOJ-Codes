#include <iostream>
#include <algorithm>

using namespace std;

/* 얼핏 보면 DFS문제 같지만, 트리에서는 Cycle이 존재하지 않으므로
 * leaf를 제외한 모든 정점은 단절점이고, 모든 간선은 단절선이다.
 * 단절점 질의에서 leaf만 체크해주면 끝
 */

int N, Q;
int conn[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	int a, b;
	for (int i = 1; i < N; ++i)
	{
		cin >> a >> b;
		++conn[a];
		++conn[b];
	}
	
	cin >> Q;
	
	while (Q--)
	{
		cin >> a >> b;

		if (a == 1)
		{
			// 연결된 간선이 1개면 leaf
			cout << ((conn[b] == 1) ? "no\n" : "yes\n");
		}
		else
		{
			cout << "yes\n";
		}
	}

	return 0;
}