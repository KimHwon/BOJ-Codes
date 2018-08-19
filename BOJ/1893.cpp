// C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char dic[127];

int kmp(string str, vector<char> pttn)
{
	vector<int> pi(pttn.size(), 0);

	int eq = 0;
	for (int i = 1; i < pttn.size(); ++i)
	{
		while (eq && pttn[i] != pttn[eq])
		{
			eq = pi[eq - 1];
		}
		if (pttn[i] == pttn[eq])
		{
			++eq;
			pi[i] = eq;
		}
	}

	int cnt = 0; eq = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		while (eq && str[i] != pttn[eq])
		{
			eq = pi[eq - 1];
		}
		if (str[i] == pttn[eq])
		{
			++eq;

			if (eq == pttn.size())
			{
				++cnt;

				eq = pi[eq - 1];
			}
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--)
	{
		string ord;
		string org, enc;
		cin >> ord >> org >> enc;

		vector<int> sftVec;
		for (int sft = 0; sft < ord.size(); ++sft)	// sft만큼 쉬프트
		{
			for (int i = 0; i < ord.size(); ++i)
			{
				// 문자변환 테이블
				dic[ord[i]] = ord[(i + sft) % ord.size()];
			}

			vector<char> sfted;	// 쉬프트한 평문
			for (char c : org)
			{
				sfted.push_back(dic[c]);
			}
			
			if (kmp(enc, sfted) == 1)
			{
				sftVec.push_back(sft);
			}
		}

		// Case별 출력
		switch (sftVec.size())
		{
		case 0:
			cout << "no solution\n";
			break;
		case 1:
			cout << "unique: " << sftVec[0] << '\n';
			break;
		default:
			cout << "ambiguous:";
			for (int s : sftVec)
			{
				cout<< ' ' << s ;
			}
			cout << '\n';
		}
	}

	return 0;
}
