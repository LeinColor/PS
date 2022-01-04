#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1234567890;
int arr[100001];
int main()
{
	int N, S; cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int a = 0, b = 0, sum = arr[0], len = INF;
	while (a <= b && b < N) {
		if (sum < S) {
			sum += arr[++b];
		}
		else if (sum == S) {
			len = min(len, (b - a + 1));
			sum += arr[++b];
		}
		else if (sum > S) {
			len = min(len, (b - a + 1));
			sum -= arr[a++];
		}
	}
	if (len == INF)
		cout << '0';
	else
		cout << len;
	return 0;
}