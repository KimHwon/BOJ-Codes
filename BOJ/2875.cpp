#include <iostream>

using namespace std;

int F, M, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> F >> M >> K;

	int team;
	for (team = 0; team * 2 <= F && team <= M && F + M - team * 3 >= K; ++team) ;

	cout << team - 1;

	return 0;
}