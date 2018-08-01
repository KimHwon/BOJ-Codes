#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int N;
vector<int> pstArr, ngtArr;
int one;

/* 합이 최대가 되려면,
 * i) 음수 || 0
 *		오름차순으로 둘씩 묶어서 더한다.
 *		가능한 (큰 음수 * 큰 음수)로 만든다. 또는 0과 곱해 없앤다
 * ii) 1이 아닌 양수
 *		내림차순으로 둘씩 묶어서 더한다.
 *		가능한 (큰 양수 * 큰 양수)로 만든다
 * iii) 1
 *		묶지 않고 더한다.
 *		1과 묶으면 1이 되므로 어떤 수와 묶던지 더 작아짐
 */

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	int a;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;

		if (a < 1)
		{
			ngtArr.push_back(a);
		}
		else if (a > 1)
		{
			pstArr.push_back(a);
		}
		else
		{
			++one;
		}
	}

	sort(ngtArr.begin(), ngtArr.end());
	sort(pstArr.begin(), pstArr.end(), greater<int>());

	long long sum = 0;
	for (int i = 0; i + 1 < ngtArr.size(); i += 2)
	{
		sum += ngtArr[i] * ngtArr[i + 1];
	}
	if (ngtArr.size() % 2)
	{
		sum += ngtArr.back();
	}

	for (int i = 0; i + 1 < pstArr.size(); i += 2)
	{
		sum += pstArr[i] * pstArr[i + 1];
	}
	if (pstArr.size() % 2)
	{
		sum += pstArr.back();
	}

	sum += one;


	cout << sum;

	return 0;
}