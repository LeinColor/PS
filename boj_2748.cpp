#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	int n; cin >> n;

	ll dp[91];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
	return 0;
}