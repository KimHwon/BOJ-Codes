// C++11
#include <iostream>

#define FOR(i, n) for (int i = 0; i < n; ++i)
#define MAX(a, b) (((a) > (b)) ? (a) : (b) )
#define MIN(a, b) (((a) < (b)) ? (a) : (b) )

using namespace std;

int hist[100000];

int area(int left, int right)
{
	if (left == right)		// 1칸만 있는 경우
	{
		return hist[left];
	}

	int center = (left + right) / 2;

	int r = MAX(area(left, center), area(center + 1, right));	// 양쪽으로 분할하여 재귀 호출

	int low = center, high = center + 1;
	int height = MIN(hist[low], hist[high]);		// 가운데 2칸을 포함하는 경우
								// 여기서부터 확장해 나가면서 계산해본다
	r = MAX(r, height * 2);
	while (left < low || high < right)
	{
		if (high < right && (low == left || hist[low - 1] < hist[high + 1])) // 높이가 높은쪽 우선 확장
		{
			++high;
			height = MIN(height, hist[high]);
		}
		else
		{
			--low;
			height = MIN(height, hist[low]);
		}

		r = MAX(r, height * (high - low + 1));		// 확장한 후의 넓이
	}

	return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;

	cin >> N;
	FOR(i, N)
	{
		cin >> hist[i];
	}

	cout << area(0, N - 1);

	return 0;
}
