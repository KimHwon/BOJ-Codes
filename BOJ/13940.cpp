#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N, M;
string brd[2000];
bool vst[2000][2000];

vector<pair<int, int>> path, nxt;
// vii path : 가능한 경우들
// greedy하게 가능한 작게 선택하되, 같은 값이 있으면 nxt에 추가해서 다음 위치도 확인

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> brd[i];
	}

	path.push_back(make_pair(0, 0));
	while (!path.empty())
	{
		auto pos = path.back();
		cout << brd[pos.first][pos.second];

		// path에서 이동할 수 있는 위치 중, 가장 작은 값 mn를 찾음
		char mn = 'z';
		for (auto p : path)
		{
			if (p.first + 1 < N && p.second < M)
			{
				mn = min(mn, brd[p.first + 1][p.second]);
			}
			if (p.first < N && p.second + 1 < M)
			{
				mn = min(mn, brd[p.first][p.second + 1]);
			}
		}

		// mn위치를 nxt에 추가
		for (auto p : path)
		{
			if (p.first + 1 < N && p.second < M && !vst[p.first + 1][p.second])
			{
				if (brd[p.first + 1][p.second] == mn)
				{
					nxt.push_back(make_pair(p.first + 1, p.second));
					vst[p.first + 1][p.second] = true;
				}
			}
			if (p.first < N && p.second + 1 < M && !vst[p.first][p.second + 1])
			{
				if (brd[p.first][p.second + 1] == mn)
				{
					nxt.push_back(make_pair(p.first, p.second + 1));
					vst[p.first][p.second + 1] = true;
				}
			}
		}

		path = nxt;
		nxt.clear();
	}

	return 0;
}
