#include <stdio.h>
typedef long long ll;

ll N, A, i;
int main()
{
	scanf("%lld", &N);
	while (A < N)
		A += ++i;
	if (i % 2 == 0) printf("%lld", i - A + N);
	else printf("%lld", A - N + 1);
	printf("/");
	if (i % 2 == 1) printf("%lld", i - A + N);
	else printf("%lld", A - N + 1);
	return 0;
}