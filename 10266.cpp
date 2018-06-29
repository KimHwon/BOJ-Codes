// C++11
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

// 바늘 사이 각도 차이
vector<int> delta(vector<int> vec)
{
	vector<int> dt;
	sort(vec.begin(), vec.end());

	for (int i = 1; i < vec.size(); ++i)
	{
		dt.push_back(vec[i] - vec[i - 1]);
	}
	dt.push_back(vec[0] + 360000 - vec.back());

	return dt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a;
	vector<int> hand, dh1, dh2;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		hand.push_back(a);
	}
	dh1 = delta(hand);

	hand.clear();
	for (int i = 0; i < N; ++i)
	{
		cin >> a;
		hand.push_back(a);
	}
	dh2 = delta(hand);

	// 환형구조를 모두 탐색하기 위해 2번 반복
	int l = dh1.size();
	for (int i = 0; i < l; ++i)
	{
		dh1.push_back(dh1[i]);
	}

	// KMP Search
	vector<int> jmp(dh2.size(), 0);
	int eq = 0;
	for (int i = 1; i < dh2.size(); ++i)
	{
		while (eq && dh2[i] != dh2[eq])
		{
			eq = jmp[eq - 1];
		}
		if (dh2[i] == dh2[eq])
		{
			++eq;
			jmp[i] = eq;
		}
	}

	eq = 0;
	for (int i = 0; i < dh1.size(); ++i)
	{
		while (eq && dh1[i] != dh2[eq])
		{
			eq = jmp[eq - 1];
		}
		if (dh1[i] == dh2[eq])
		{
			++eq;

			if (eq == dh2.size())
			{
				cout << "possible\n";
				return 0;
			}
		}
	}

	cout << "impossible\n";
	return 0;
}
