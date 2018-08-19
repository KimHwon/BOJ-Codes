#include <iostream>
#include <algorithm>

using namespace std;

int C, R;
int land[1000][1000];

/* 참고 자료 : https://www.slideshare.net/Baekjoon/baekjoon-online-judge-2873
 * 체스판의 모든 칸을 방문하는 문제로 변형될 수 있다
 * 가로 또는 세로가 홀수칸 일 경우 모든 칸을 방문할 수 있다 - 모든 칸을 방문
 * 가로와 세로가 짝수일 경우 1칸은 방문할 수 없다 - 가장 즐거움이 적은 칸을 제외하고 방문 : minHappy()
 * 
 * 2줄 단위로 끊어서 생각하면,
 * 제외할 칸이 없으면 R...RDL...L 꼴로 움직인다
 * 제외할 칸이 있으면 URDR 꼴로 움직이면서 적절히 회피한다
 */

void minHappy(int& y, int& x)
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if ((i + j) % 2 == 0) continue;

			if (land[i][j] < land[y][x])
			{
				y = i; x = j;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> land[i][j];
		}
	}

	int ci = 0, cj = 0;
	if (R % 2)		// 세로가 홀수칸일 경우
	{
		bool right = true;

		while (!(ci == R - 1 && cj == C - 1))
		{
			if (right)
			{
				if (cj + 1 < C)
				{
					cout << 'R';
					++cj;
				}
				else
				{
					cout << 'D';
					++ci;

					right = false;
				}
			}
			else
			{
				if (cj - 1 >= 0)
				{
					cout << 'L';
					--cj;
				}
				else
				{
					cout << 'D';
					++ci;

					right = true;
				}
			}
		}
	}
	else if (C % 2)		// 가로가 홀수칸일 경우
	{
		bool down = true;

		while (!(ci == R - 1 && cj == C - 1))
		{
			if (down)
			{
				if (ci + 1 < R)
				{
					cout << 'D';
					++ci;
				}
				else
				{
					cout << 'R';
					++cj;

					down = false;
				}
			}
			else
			{
				if (ci - 1 >= 0)
				{
					cout << 'U';
					--ci;
				}
				else
				{
					cout << 'R';
					++cj;

					down = true;
				}
			}
		}
	}
	else		// 둘 다 짝수칸일 경우
	{
		int mi = 0, mj = 1;
		minHappy(mi, mj);

		for (int i = 0; i < R; i += 2)
		{
			if (mi == i || mi == i + 1)
			{
				ci = i;
				
				bool passed = false;

				while (true)
				{
					if (ci + 1 == mi && cj == mj)
					{
						cout << "RD";
						++ci; ++cj;

						passed = true;
					}
					else if (cj + 1 == mj && ci == mi)
					{
						cout << "DR";
						++ci; ++cj;

						passed = true;
					}
					else
					{
						cout << (passed ? "URD" : "DRU");
						++cj;
					}

					if (ci == i + 1 && cj == C - 1) break;
					else
					{
						cout << 'R';
						++cj;
					}
				}
			}
			else
			{
				if (cj == 0)
				{
					for (int j = 1; j < C; ++j) cout << 'R';
					cout << 'D';
					for (int j = 1; j < C; ++j) cout << 'L';
				}
				else
				{
					for (int j = 1; j < C; ++j) cout << 'L';
					cout << 'D';
					for (int j = 1; j < C; ++j) cout << 'R';
				}
			}

			if (i + 1 < R - 1) cout << 'D';
		}
	}

	return 0;
}