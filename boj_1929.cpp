#include <iostream>
using namespace std;

const int MAX = 1000001;
bool isPrime[MAX];
int main()
{
	fill(isPrime + 2, isPrime + MAX, true);
	for (int i = 2; i < MAX; i++) {
		for (int j = i * 2; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}

	int M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (isPrime[i])
			cout << i << '\n';
	}

	return 0;
}