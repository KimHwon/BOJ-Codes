#include <iostream>
#include <algorithm>

#define ull unsigned long long

using namespace std;

ull H, W;

/* i) H = 1
 *		�� ������
 * ii) H = 2
 *		min(3, (w - 1) / 2) + 1
 *		URR �������̳� DRR �����Ӹ� �����ϹǷ� 4ȸ �̻� ������ �� ����
 * iii) H >= 3
 *		H�� ���� ������ ���� - W�� ������
 *		j) W >= 7
 *			cycle�� ������ ��, W-3 ȸ �����δ� (�ͳ��� �ؼ�)
 *		jj) W < 7
 *			4���� �������� ����ϴ� cycle�� �Ұ��� �� ��, 4ȸ �̻� ������ �� ����
 */

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;

	if (H == 1)
	{
		cout << 1;
	}
	else if (H == 2)
	{
		cout << min((ull)3, (W - 1) / 2) + 1;
	}
	else
	{
		if (W >= 7)
		{
			cout << W - 2;
		}
		else
		{
			cout << min((ull)3, W - 1) + 1;
		}
	}

	return 0;
}