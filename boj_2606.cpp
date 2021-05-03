#include <iostream>
using namespace std;

int N, K;
int arr[101][101];
bool visited[101];
int answer;
void dfs(int n)
{
	visited[n] = true;
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && arr[n][i]) {
			dfs(i);
			answer++;
		}
	}
}
int main()
{
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	dfs(1);
	cout << answer;
	return 0;
}