#include <iostream>
#include <string>

#define ull unsigned long long

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	// 입력이 최대 1000000자리이므로 첫 연산은 string으로 해야 한다
	if (str.length() == 1)
	{
		cout << 0 << '\n' << (((str[0] - '0') % 3) ? "NO" : "YES");

		return 0;
	}

	ull sum = 0, n = 0;
	int cnt;
	// 두번째 연산부터는 자릿수가 줄었기에, ull로 해도 충분하다
	for (int i = 0; i < str.length(); i++)
	{
		n += str[i] - '0';
	}

	for (cnt = 1; n >= 10; ++cnt)
	{
		sum = 0;
		while (n)
		{
			sum += n % 10;
			n /= 10;
		}
		n = sum;
	}

	cout << cnt << '\n' << ((n % 3) ? "NO" : "YES");

	return 0;
}
