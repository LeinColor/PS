#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime[10001];
int main()
{
	fill(isPrime + 2, isPrime + 10001, true);
	for (int i = 2; i <= 10000; i++) {
		for (int j = i * i; j <= 10000; j += i) {
			isPrime[j] = false;
		}
	}

	int M, N, sum = 0, mn = 123456789;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (isPrime[i]) {
			sum += i;
			mn = min(mn, i);
		}
	}
	if (sum == 0)
		cout << "-1";
	else
		cout << sum << '\n' << mn;

	return 0;
}