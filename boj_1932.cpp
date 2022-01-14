#include <iostream>
#include <algorithm>
using namespace std;

int dp[501];
int main()
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int x; cin >> x;
	dp[0] = x;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			int x; cin >> x;
			dp[i] = max(dp[i], dp[i - 1] + x);
		}
	}
	for (int i = 0; i < N; i++)
		cout << dp[i] << ' ';
	cout << '\n';
	cout << dp[N - 1];
	return 0;
}