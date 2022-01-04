#include <iostream>
using namespace std;

int N, M;
int arr[9];
bool visited[9];
void dfs(int current)
{
	if (current == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[current] = i + 1;
			dfs(current + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M;
	dfs(0);
	return 0;
}