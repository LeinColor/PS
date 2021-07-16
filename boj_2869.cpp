#include <stdio.h>
#include <math.h>

int main()
{
	double A, B, V;
	scanf("%lf%lf%lf", &A, &B, &V);
	printf("%d", (int)ceil((V - B) / (A - B)));
	return 0;
}