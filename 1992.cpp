// C++11
#include <iostream>
#include <vector>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;

char pic[65][65];
vector<char> zip;

void zipPic(int x, int y, int sz)   // Params : x-offset, y-offset, width&&height
{
	if (sz == 1)
	{
		zip.push_back(pic[x][y] + '0'); // 1칸짜리 칸이면 그대로 출력 (더 이상 분해할 수 없음)
		return;
	}

	int flag = pic[x][y];
	for (int i = x; i < x + sz; i++)
	{
		for (int j = y; j < y + sz; j++)
		{
			if (flag != pic[i][j])         // 영역 전체가 같은 종류의 데이터인지 체크
			{
				zip.push_back('(');          // 아니라면 괄호 열고 재귀돌림
				zipPic(x, y, sz / 2);
				zipPic(x + sz / 2, y, sz / 2);
				zipPic(x, y + sz / 2, sz / 2);
				zipPic(x + sz / 2, y + sz / 2, sz / 2);
				zip.push_back(')');

				return;
			}
		}
	}

	zip.push_back(pic[x][y] + '0');    // 맞다면 그대로 출력
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	FOR(i, n)
	{
		FOR(j, n)
		{
			cin >> pic[j][i];
			pic[j][i] -= '0';   // 연산의 편의를 위해 '0'->0, '1'->1 로 변경 (지금 생각하면 별 쓸데 없다)
		}
	}

	zipPic(0, 0, n);
	
	for (auto iter = zip.begin(); iter < zip.end(); ++iter)
	{
		cout << (*iter);
	}

	return 0;
}
