#include <iostream>
using namespace std;

const int MAX = 10001;
bool isPrime[MAX];
int main()
{
	fill(isPrime + 2, isPrime + MAX, true);
	for (int i = 2; i < MAX; i++) {
		for (int j = i * i; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = n / 2; i >= 1; i--) {
			if (isPrime[i] && isPrime[n - i]) {
				cout << i << ' ' << n - i << '\n';
				break;
			}
		}
	}
	return 0;
}