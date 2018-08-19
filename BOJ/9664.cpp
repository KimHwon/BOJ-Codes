#include <iostream>

using namespace std;

int N, O;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> O;

	// 막내가 가져간 메달을 제외하고, 1인당 메달 수
	int perMax = O / (N - 1);

	if (perMax * (N - 1) == O)
	{
		// 막내가 smaller한 갯수를 가져가므로 -1
		cout << (O + perMax - 1) << " " << (O + perMax);
	}
	else
	{
		cout << (O + perMax) << " " << (O + perMax);
	}

	return 0;
}