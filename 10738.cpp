#include <iostream>
#include <algorithm>

using namespace std;

int K, S, T;
int price[21], sets[5], eat[21];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	for (int i = 1; i <= K; ++i)
	{
		cin >> price[i];
	}

	cin >> S;
	for (int i = 1; i <= 4; ++i)
	{
		cin >> sets[i];
	}

	cin >> T;
	int a;
	// eat : 먹고 싶은 메뉴
	for (int i = 0; i < T; ++i)
	{
		cin >> a;
		++eat[a];
	}

	int mn = 1e9;
	for (int i = 0; i < 20; ++i)
	{
		int p = i * S;	// 세트메뉴를 i개 구매

		int tmp[21];	for (int k = 0; k <= 20; ++k) tmp[k] = eat[k];	// tmp = eat

		for (int j = 1; j <= 4; ++j)
		{
			// 세트메뉴 갯수만큼 제외
			tmp[sets[j]] -= i;
		}

		for (int j = 1; j <= 20; ++j)
		{
			// 남은 메뉴들 계산
			if (tmp[j] > 0)
			{
				p += price[j] * tmp[j];
			}
		}

		mn = min(mn, p);
	}

	cout << mn;

	return 0;
}
