#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10001];
int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	vector<int> dist(N - 1, 0);
	for (int i = 0; i < dist.size(); i++)
		dist[i] = arr[i + 1] - arr[i];
	sort(dist.begin(), dist.end());

	int answer = 0;
	for (int i = 0; i < N - K; i++)
		answer += dist[i];
	cout << answer;
	return 0;
}