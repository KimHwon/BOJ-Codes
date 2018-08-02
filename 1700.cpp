#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

int use[100];
int plug[100];

bool toUnplug(int n)
{
	for (int i = 0; i < N; ++i)
	{
		if (plug[i] == n)	// 이미 꽂혀 있음
		{
			return false;
		}

		if (plug[i] == 0)	// 빈 콘센트가 있음
		{
			plug[i] = n;

			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < K; ++i)
	{
		cin >> use[i];
	}

	int cnt = 0;
	for (int i = 0; i < K; ++i)
	{
		// 가장 오랫동안 사용하지 않을 플러그를 뽑는다
		if (toUnplug(use[i]))
		{
			int faridx, fardst = -1;
			for (int j = 0; j < N; j++)
			{
				int dst = 0;
				for (int k = i + 1; k < K && plug[j] != use[k]; ++k)
				{
					++dst;
				}

				if (dst > fardst)
				{
					faridx = j;
					fardst = dst;
				}
			}

			plug[faridx] = use[i];
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}