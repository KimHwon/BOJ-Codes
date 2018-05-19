// C++11
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, char>> tree[10001];
int N;

int longest = 0;
int dfs(int me)
{
	int len, maxLen = 0, sndLen = 0;
	// me를 중심으로 한 지름 = 가장 먼 노드(maxLen) + 두번째로 먼 노드(sndLen)
	for (auto c : tree[me])
	{
		len = dfs(c.first) + c.second;
		if (len > maxLen)	// len > maxLen > sndLen
		{
			sndLen = maxLen;
			maxLen = len;
		}
		else if (len > sndLen)	// maxLen > len > sndLen
		{
			sndLen = len;
		}
	}

	// longest = 트리에서 가장 긴 지름
	if (longest < (maxLen + sndLen))
	{
		longest = maxLen + sndLen;	
	}

	return maxLen;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int p, c, d;

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> p >> c >> d;
		tree[p].push_back(make_pair(c, d));
	}

	dfs(1);

	cout << longest;
	
	return 0;
}
