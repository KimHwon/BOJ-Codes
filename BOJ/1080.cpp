#include <iostream>
#include <string>

using namespace std;

int N, M;
int table[50][50];
int target[50][50];

void flip(int x, int y)
{
	for (int i = x - 1; i <= x + 1; ++i)
	{
		for (int j = y - 1; j <= y + 1; ++j)
		{
			table[i][j] = !table[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	string str;
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		for (int j = 0; j < M; ++j)
		{
			table[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		for (int j = 0; j < M; ++j)
		{
			target[i][j] = str[j] - '0';
		}
	}

	int cnt = 0;
	for (int i = 1; i < N - 1; ++i)
	{
		for (int j = 1; j < M - 1; ++j)
		{
			if (table[i - 1][j - 1] != target[i - 1][j - 1])
			{
				flip(i, j);
				++cnt;
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (table[i][j] != target[i][j])
			{
				cout << -1;

				return 0;
			}
		}
	}

	cout << cnt;

	return 0;
}