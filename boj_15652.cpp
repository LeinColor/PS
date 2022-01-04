#include <iostream>
using namespace std;

int N, M;
int arr[9];
void dfs(int depth, int current)
{
	if (depth == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = current; i < N; i++) {
		arr[depth] = i + 1;
		dfs(depth + 1, i);
	}
}

int main()
{
	cin >> N >> M;
	dfs(0, 0);
	return 0;
}