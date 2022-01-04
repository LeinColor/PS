#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll tree[1000001];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, M;
	cin >> N >> M;
	for (ll i = 0; i < N; i++)
		cin >> tree[i];
	ll lo = 0, hi = 2000000001, mid = 0;
	while (lo + 1 < hi) {
		ll sum = 0;
		mid = (lo + hi) / 2;
		for (ll i = 0; i < N; i++) {
			if (tree[i] > mid)
				sum += (tree[i] - mid);
		}
		if (sum < M) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	cout << lo;
	return 0;
}