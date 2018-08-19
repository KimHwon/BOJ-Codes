#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int t = 1; ; ++t)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (!(a || b || c))
		{
			return 0;
		}

		if (c < 0)
		{
			// 빗변은 항상 성립함
			double l = sqrt(a * a + b * b);
			printf("Triangle #%d\nc = %.3lf\n\n", t, l);
		}
		else if (a < 0)
		{
			long long l2 = c * c - b * b;

			if (l2 <= 0)
			{
				// 빗변이 더 짧은 경우
				printf("Triangle #%d\nImpossible.\n\n", t);
			}
			else
			{
				printf("Triangle #%d\na = %.3lf\n\n", t, sqrt(l2));
			}
		}
		else
		{
			long long l2 = c * c - a * a;

			if (l2 <= 0)
			{
				// 빗변이 더 짧은 경우
				printf("Triangle #%d\nImpossible.\n\n", t);
			}
			else
			{
				printf("Triangle #%d\nb = %.3lf\n\n", t, sqrt(l2));
			}
		}
	}

	return 0;
}
