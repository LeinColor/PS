#include <iostream>
using namespace std;

bool isPrime[1001];
int main()
{
	fill(isPrime + 2, isPrime + 1001, true);
	for (int i = 2; i <= 1000; i++) {
		for (int j = i * i; j <= 1000; j += i) {
			isPrime[j] = false;
		}
	}

	int N, answer = 0;
	cin >> N;
	while (N--) {
		int K;
		cin >> K;
		if (isPrime[K]) answer++;
	}
	cout << answer;
	return 0;
}