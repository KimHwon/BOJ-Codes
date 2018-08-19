#include <iostream>
#include <algorithm>
#include <string>

#define VAL(c) table[c - 'A']

using namespace std;

int table[26];

// 문제 분류는 DP지만, Greedy로도 충분히 풀 수 있다

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str, ins;

	cin >> str >> ins;
	cin >> VAL('A') >> VAL('C') >> VAL('G') >> VAL('T');

	int mn = 1e9;
	for (int i = 0; i <= str.size(); ++i)
	{
		int sum = 0;

		int ofs = i;
		for (int j = 0; j < ins.size(); ++j)
		{
			// 다르면 삽입, 같으면 넘어감
			if (str[ofs] != ins[j])
			{
				sum += VAL(ins[j]);
			}
			else
			{
				++ofs;
			}
		}

		mn = min(mn, sum);
	}

	cout << mn;

	return 0;
}