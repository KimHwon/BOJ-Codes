#include <iostream>
#include <vector>

using namespace std;

int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		cin >> N;
		if (N < 0)
		{
			return 0;
		}

		vector<int> div;
		long sum = 0;
		for (int i = 1; i < N; ++i)
		{
			if (N % i == 0)
			{
				sum += i;
				div.push_back(i);
			}
		}

		if (sum == N)
		{
			cout << N << " = " << div[0];

			for (int i = 1; i < div.size(); ++i)
			{
				cout << " + " << div[i];
			}
			cout << '\n';
		}
		else
		{
			cout << N << " is NOT perfect.\n";
		}
	}

	return 0;
}
