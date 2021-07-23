#include <iostream>
#include <algorithm>
using namespace std;

int dp[16], T[16], P[16];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
		if (i + T[i] <= N) {
			dp[i] = P[i];
		}

	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i + T[i] <= j && j + T[j] <= N) {
				dp[j] = max(dp[j], dp[i] + P[j]);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
		answer = max(answer, dp[i]);
	cout << answer;
	return 0;
}