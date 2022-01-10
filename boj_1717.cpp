#include <iostream>
using namespace std;

const int MAX_N = 1000002;
int p[MAX_N];
int find(int n)
{
	if (p[n] < 0) return n;
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
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < MAX_N; i++) {
		p[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		int x, a, b;
		cin >> x >> a >> b;
		if (x == 0) merge(a, b);
		else if (x == 1) {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}