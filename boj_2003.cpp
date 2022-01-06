#include <iostream>
using namespace std;

int A[10001];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	int left = 0, right = 0, sum = 0, ans = 0;
	while (right <= N) {
		if (sum < M) sum += A[right++];
		else sum -= A[left++];
		if (sum == M) ans++;
	}
	cout << ans;
	return 0;
}