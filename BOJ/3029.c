#include <stdio.h>

int main(void)
{
	int stt[3], edt[3];
	// stt: start time, edt: end time, [0]=h [1]=m [2]=s
	scanf("%2d:%2d:%2d\n%2d:%2d:%2d", &stt[0], &stt[1], &stt[2], &edt[0], &edt[1], &edt[2]);
	
	// 전부 sec로 변환
	int sts = stt[0] * 3600 + stt[1] * 60 + stt[2];
	int eds = edt[0] * 3600 + edt[1] * 60 + edt[2];

	int dur = (sts < eds) ? (eds - sts) : (86400 - sts + eds);
	printf("%02d:%02d:%02d", dur / 3600, (dur % 3600) / 60, dur % 60);

	return 0;
}
