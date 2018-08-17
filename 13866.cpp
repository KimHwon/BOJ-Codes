#include <iostream>
#include <algorithm>

using namespace std;

int mem[4];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 4; ++i)
	{
		cin >> mem[i];
	}

	int mn = 1e9;
	// try every permutations
	do {
		mn = min(mn, abs((mem[0] + mem[1]) - (mem[2] + mem[3])));
	} while (next_permutation(mem, mem + 4));

	cout << mn;

	return 0;
}
