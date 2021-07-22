#include <stdio.h>

char s[51][51];
int min(int a, int b)
{
	return a < b ? a : b;
}

int GetModifiedCount(int x, int y, int N, int M)
{
	int ret = 0;
	int count = 0;

	// case 1
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0 && s[i][j] != 'W')
					count++;
				else if (j % 2 == 1 && s[i][j] != 'B')
					count++;
			}
			else {
				if (j % 2 == 0 && s[i][j] != 'B')
					count++;
				else if (j % 2 == 1 && s[i][j] != 'W')
					count++;
			}
		}
	}

	ret = count;
	count = 0;

	// case 2
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0 && s[i][j] != 'B')
					count++;
				else if (j % 2 == 1 && s[i][j] != 'W')
					count++;
			}
			else {
				if (j % 2 == 0 && s[i][j] != 'W')
					count++;
				else if (j % 2 == 1 && s[i][j] != 'B')
					count++;
			}
		}
	}

	return min(ret, count);
}

int main()
{
	int ans = 987654321;
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &s[i]);
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			ans = min(ans, GetModifiedCount(i, j, N, M));
		}
	}
	printf("%d", ans);
	return 0;
}