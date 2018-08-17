#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> arr;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		arr.push_back(i);
	}

	do
	{
		for (int i : arr)
		{
			cout << i << ' ';
		}
		cout << '\n';
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}
