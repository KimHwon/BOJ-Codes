//C++11
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a;

	cin >> N;

	vec.push_back(0);
	for (int i = 0; i < N; ++i)
	{
		cin >> a;

		if (vec.back() < a)
		{
			vec.push_back(a);
		}
		else
		{
			auto iter = lower_bound(vec.begin(), vec.end(), a);
			*iter = a;
		}
	}

	cout << vec.size() - 1;

	return 0;
}
