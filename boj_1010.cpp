#include <stdio.h>

int dp[31][31];
int main()
{
	dp[0][0] = 1;
	for (int i = 1; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			if (j == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d%d", &N, &M);
		printf("%d\n", dp[M][N]);
	}
	return 0;
}