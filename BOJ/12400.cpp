#include <iostream>
#include <string>

using namespace std;

char table[127];
int N;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 예제에 있는 문자열들로 규칙을 알 수 있다 (a ~ z 까지 전부 나옴)
	string enc = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee z";
	string dec = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo q";

	for (int i = 0; i < enc.size(); ++i)
	{
		if (enc[i] == ' ') continue;

		table[enc[i]] = dec[i];
	}

	// 실제 테스트 케이스를 처리하는 부분
	cin >> N;
	cin.ignore();	// ignore Enter Key
	for (int i = 1; i <= N; ++i)
	{
		string str;
		getline(cin, str);

		cout << "Case #" << i << ": ";
		for (char c : str)
		{
			cout << ((c == ' ') ? ' ' : table[c]);
		}
		cout << '\n';
	}

	return 0;
}
