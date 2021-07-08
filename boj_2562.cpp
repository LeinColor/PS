#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int mx = 0, k;
	for (int i = 1; i <= 9; i++) {
		int N;
		cin >> N;
		if (mx < N) {
			k = i;
			mx = max(mx, N);
		}
	}
	cout << mx << '\n' << k;
	return 0;
}