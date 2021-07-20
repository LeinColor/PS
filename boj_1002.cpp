#include <stdio.h>
#include <math.h>

int T;
double x1, y11, r1, x2, y2, r2, d, sum, sub;
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y11, &r1, &x2, &y2, &r2);
		d = sqrt((x1 - x2) * (x1 - x2) + (y11 - y2) * (y11 - y2));
		sum = r1 + r2;
		sub = fabs(r1 - r2);
		if (x1 == x2 && y11 == y2) {
			if (r1 == r2)
				printf("-1\n");
			else
				printf("0\n");
		}
		else {
			if (sub < d && d < sum) printf("2\n");
			else if (sum == d || sub == d) printf("1\n");
			else if (sum < d || sub > d) printf("0\n");
		}
	}
	return 0;
}