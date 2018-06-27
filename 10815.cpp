//C++11
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> a;
		cout << (int)binary_search(vec.begin(), vec.end(), a) << ' ';
	}

	return 0;
}
