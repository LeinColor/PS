#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, mn = 1000001, mx = -1000001;
	cin >> N;
	while (N--) {
		int K;
		cin >> K;
		mn = min(mn, K);
		mx = max(mx, K);
	}
	cout << mn << ' ' << mx;
	return 0;
}