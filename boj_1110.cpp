#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int K = N, answer = 0;
	while (true) {
		int A = K % 10;
		int B = ((K / 10) + (K % 10)) % 10;
		K = (A * 10) + B;
		answer++;

		if (K == N)
			break;
	}
	cout << answer;

	return 0;
}