#include <stdio.h>

int main()
{
	int T, x, y, dist, warp;
	scanf("%d", &T);
	while (T--) {
		warp = 0;
		scanf("%d%d", &x, &y);
		dist = y - x;

		long long n, lo, hi, po;
		for (n = 1;; n++) {
			po = n * n;
			lo = po - n + 1;
			hi = po + n;
			if (lo <= dist && dist <= hi) {
				if (lo <= dist && dist <= po) warp = n * 2 - 1;
				else warp = n * 2;
				break;
			}
		}
		printf("%d\n", warp);
	}
	return 0;
}