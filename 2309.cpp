#include <iostream>
#include <algorithm>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int arr[9], sum;
	FOR(i, 9)
	{
		cin >> arr[i];
	}
	sort(arr, arr + 9);   // 오름차순 출력을 위해 미리 정렬해둠

	FOR(i, 9)
	{
		FOR(j, i)         // 가짜 난쟁이 arr[i], arr[j]를 모두 체크
		{
			sum = 0;

			FOR(k, 9)       // 가짜 난쟁이를 제외하고 계산해 봄
			{
				if (k == i || k == j) continue;

				sum += arr[k];
			}

			if (sum == 100)
			{
				FOR(k, 9)       // 가짜 난쟁이 발견시 해당 난쟁이를 제외하고 출력
				{
					if (k == i || k == j) continue;

					cout << arr[k] << "\n";
				}

				return 0;
			}
		}
	}

	return 0;
}
