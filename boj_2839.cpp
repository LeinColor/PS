#include <stdio.h>

int N, a, b, c = 10000;
int min(int a, int b) { return a < b ? a : b; }
int main()
{
	scanf("%d", &N);
	b = N / 5;
	while (b >= 0) {
		if ((N - (5 * b)) % 3 == 0) {
			c = min(c, b + (N - 5 * b) / 3);
		}
		b--;
	}
	if (c == 10000) puts("-1");
	else printf("%d", c);
}