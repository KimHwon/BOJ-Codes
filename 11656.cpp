// C++11
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> order;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	while (!str.empty())
	{
		order.push_back(str);

		str.erase(str.begin());
	}
	sort(order.begin(), order.end());

	for (string s : order)
	{
		cout << s << '\n';
	}

	return 0;
}
