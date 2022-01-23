#include <stdio.h>
#include <string.h>
#define MAXN 1000001

int p[MAXN];
int n, m;
int find(int n)
{
	if (p[n] == -1) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(p, -1, sizeof(p));

	for (int i = 0; i < m; i++) {
		int k, a, b;
		scanf("%d%d%d", &k, &a, &b);
		if (k == 0) merge(a, b);
		else {
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}