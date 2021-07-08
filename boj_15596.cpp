#include <stdio.h>

bool b[10001];
void d(int n)
{
	int m = n;
	while (m > 0) {
		n += m % 10;
		m /= 10;
	}
	b[n] = true;
}
int main()
{
	for (int i = 1; i <= 10000; i++)
		d(i);
	for (int i = 1; i <= 10000; i++)
		if (!b[i])
			printf("%d\n", i);
	return 0;
}