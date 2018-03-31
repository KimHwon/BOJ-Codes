// C++11
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int mon[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char week[][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int m, d;
	cin >> m >> d;

	int dsum = d;         // dsum : 지나간 날짜의 총합
	for (int i = 0; i < m; i++)
	{
		dsum += mon[i];     // 전월까지 지나간 날짜의 합
	}

	cout << week[dsum % 7];

	return 0;
}
