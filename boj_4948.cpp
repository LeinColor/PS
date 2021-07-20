#include <iostream>
using namespace std;

const int MAX = 300000;
bool isPrime[MAX];
int main()
{
	fill(isPrime + 2, isPrime + MAX, true);
	for (int i = 2; i < MAX; i++) {
		for (int j = i * 2; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}
	while (true) {
		int n, answer = 0;
		cin >> n;

		if (n == 0)
			return 0;

		for (int i = n + 1; i <= 2 * n; i++) {
			if (isPrime[i])
				answer++;
		}
		cout << answer << '\n';
	}
	return 0;
}