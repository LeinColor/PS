#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int H, W, N;
		scanf("%d%d%d", &H, &W, &N);
		int M = N % H;
		int Q = N / H + 1;
		if (M == 0) {
			M = H;
			Q = N / H;
		}
		printf("%d%02d\n", M, Q);
	}
	return 0;
}