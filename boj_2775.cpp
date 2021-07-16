#include <stdio.h>

int arr[15][15];
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= 14; i++)
		arr[0][i] = i;
	for (int i = 1; i <= 14; i++) {
		for (int j = 1; j <= 14; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	while (T--) {
		int k, n;
		scanf("%d%d", &k, &n);
		printf("%d\n", arr[k][n]);
	}
	return 0;
}