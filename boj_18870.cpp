#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1000001;
int arr[MAX_SIZE];
int cpy[MAX_SIZE];
int ans[MAX_SIZE];
unordered_map<int, int> um;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, j = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (um[arr[i]] == 0)
			cpy[j++] = arr[i];
		um[arr[i]]++;
	}
	sort(cpy, cpy + j);
	for (int i = 0; i < N; i++)
		ans[i] = lower_bound(cpy, cpy + j, arr[i]) - cpy;
	for (int i = 0; i < N; i++)
		cout << ans[i] << ' ';
	return 0;
}