#include <stdio.h>

int main()
{
	int N, answer = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int K;
		scanf("%1d", &K);
		answer += K;
	}
	printf("%d", answer);
	return 0;
}