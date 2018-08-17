#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	// 첫번째 인덱스가 0이 되도록 -1
	--a; --b;
	// x변화량 + y변화량
	cout << abs((a % 4) - (b % 4)) + abs((a / 4) - (b / 4));

	return 0;
}