#include <stdio.h>

int dp[1001][1001];
int main()
{
	dp[0][0] = 1;
	for (int i = 1; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = ((dp[i - 1][j - 1] % 10007) + (dp[i - 1][j] % 10007)) % 10007;
		}
	}

	int N, K;
	scanf("%d%d", &N, &K);
	printf("%d", dp[N][K]);
	return 0;
}