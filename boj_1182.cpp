#include <iostream>
using namespace std;

int N, S, answer;
int arr[21];
bool visited[21];
void dfs(int depth, int sum)
{
	if (sum == S && depth > 0)
		answer++;

	if (depth == N) return;

	for (int i = depth; i < N; i++) {
		dfs(i + 1, sum + arr[i]);
	}

}
int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	dfs(0, 0);
	cout << answer;
	return 0;
}