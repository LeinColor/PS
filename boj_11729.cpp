#include <iostream>
#include <math.h>
using namespace std;

void func(int n, int a, int b, int c)
{
	if (n == 1)
		printf("%d %d\n", a, c);
	else {
		func(n - 1, a, c, b);
		printf("%d %d\n", a, c);
		func(n - 1, b, a, c);
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	printf("%d\n", (int)pow(2, N) - 1);
	func(N, 1, 2, 3);
	return 0;
}