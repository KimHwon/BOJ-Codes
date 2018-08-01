#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int N;
vector<int> pstArr, ngtArr;
int one;

/* ���� �ִ밡 �Ƿ���,
 * i) ���� || 0
 *		������������ �Ѿ� ��� ���Ѵ�.
 *		������ (ū ���� * ū ����)�� �����. �Ǵ� 0�� ���� ���ش�
 * ii) 1�� �ƴ� ���
 *		������������ �Ѿ� ��� ���Ѵ�.
 *		������ (ū ��� * ū ���)�� �����
 * iii) 1
 *		���� �ʰ� ���Ѵ�.
 *		1�� ������ 1�� �ǹǷ� � ���� ������ �� �۾���
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