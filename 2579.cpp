// C++11
#include <iostream>

#define LN 300+1
#define MAX(a, b) (( (a) > (b) ) ? (a) : (b))	// 매크로함수에 괄호는 꼭*100 붙입시다
						// 연산자 우선순위 꼬이면 답없음
						// 변수 양쪽에 한 쌍, 함수 전체 양쪽에 한 쌍 꼭 합시다
using namespace std;

int stair[LN];
int sum1[LN];	// 1칸 뛰어오른 경우
int sum2[LN];	// 2칸 뛰어오른 경우

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i)
	{
		cin >> stair[i];
	}

	sum1[1] = sum2[1] = stair[1];

	for (int i = 2; i <= t; ++i)
	{
		// 2칸 뛰어올랐다면 다음 계단은 1칸 뛰어오르는 경우 밖에 없음
		sum1[i] = sum2[i - 1] + stair[i];
		// 1칸 뛰어올랐다면 다음 계단은 2칸 뛰어오르는 경우와 1칸 뛰어오르는 경우 중 점수가 높은 쪽 선택
		sum2[i] = MAX(sum1[i - 2], sum2[i - 2]) + stair[i];
	}

	cout << MAX(sum1[t], sum2[t]);

	return 0;
}
