#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
char field[10][100000];
vector<int> path;

// DFS
bool move(int x, int y)
{
	if (field[x][y] == 'X')
	{
		return false;
	}
	if (y == N - 1)
	{
		return true;
	}

	field[x][y] = 'X';

	if (x + 1 <= 9)
	{
		if (move(x + 1, y + 1))
		{
			return true;
		}
	}
	else	// top bound
	{
		if (move(9, y + 1))
		{
			return true;
		}
	}

	if (x - 1 >= 0)
	{
		if (move(x - 1, y + 1))
		{
			path.push_back(y);
			return true;
		}
	}
	else	// bottom bound
	{
		if (move(0, y + 1))
		{
			path.push_back(y);
			return true;
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	string ln;
	for (int i = 0; i < 10; ++i)
	{
		cin >> ln;
		for (int j = 0; j < N; ++j)
		{
			field[i][j] = ln[j];
		}
	}

	move(9, 0);
	
	// merge continuous values
	vector<pair<int, int>> merged;
	for (int i = path.size() - 1; i >= 0; --i)
	{
		if (merged.empty() || path[i] != path[i + 1] + 1)
		{
			merged.push_back(make_pair(path[i], 1));
		}
		else
		{
			++merged.back().second;
		}
	}

	cout << merged.size() << '\n';
	for (auto p : merged)
	{
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}