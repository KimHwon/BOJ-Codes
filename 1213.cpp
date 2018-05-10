// C++11
#include <iostream>
#include <cstring>

#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;

int lib[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char name[51], pel[51];
	cin >> name;

	for (int i = 0; name[i]; ++i)
	{
		++lib[name[i] - 'A'];	// name에 쓴 문자 목록을 카운트
	}

	int len = strlen(name);
	bool canCenter = (len % 2) ? true : false; // 홀수 길이 문자열이면 중앙에 배치할 문자를 빼뒀다 마지막에 넣음
	char center;

	int iter = 0;	// 펠린드롬문자열의 인덱스
	FOR(j, 26)
	{
		if (lib[j] == 0)
		{
			continue;
		}
		else if (lib[j] % 2 == 0)
		{
			FOR(k, lib[j] / 2) // 사용된 알파벳을 양쪽 끝에서부터 배치
			{
				pel[iter] = j + 'A';
				pel[len - iter - 1] = j + 'A';
				++iter;
			}
		}
		else if (canCenter)
		{
			canCenter = false;
			center = j + 'A';	// 중앙에 배치할 문자를 빼둠
			FOR(k, lib[j] / 2)	// 사용된 알파벳을 양쪽 끝에서부터 배치
			{
				pel[iter] = j + 'A';
				pel[len - iter - 1] = j + 'A';
				++iter;
			}
		}
		else
		// 남은 경우는
		// (1) 짝수 길이 문자열에서 홀수번 쓰인 문자가 있거나
		// (2) 홀수 길이 문자열에서 홀수번 쓰인 문자가 2가지 이상일 때
		// 두 경우 모두 팰린드롬문자열이 불가능하다
		{
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}

	if (len % 2) pel[len / 2] = center;	// 빼둔 문자 배치
	pel[len] = '\0';			// 배열 마지막에 NULL 배치

	cout << pel;

	return 0;
}
