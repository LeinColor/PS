#include <stdio.h>

int dp[12][12];
int main()
{
	dp[0][0] = 1;
	for (int i = 1; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	int N, K;
	scanf("%d%d", &N, &K);
	printf("%d", dp[N][K]);
	return 0;
}