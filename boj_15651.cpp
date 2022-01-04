#include <iostream>
using namespace std;

int N, M;
int arr[9];
void dfs(int depth)
{
	if (depth == M) {
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		arr[depth] = i + 1;
		dfs(depth + 1);
	}
}

int main()
{
	cin >> N >> M;
	dfs(0);
	return 0;
}