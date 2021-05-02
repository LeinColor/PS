#include <iostream>
#include <queue>
using namespace std;

bool visited[1001];
int arr[1001][1001];
int N, M, V;
void dfs(int x)
{
	visited[x] = true;
	cout << x << " ";

	for (int i = 1; i <= N; i++) {
		if (!visited[i] && arr[x][i]) {
			dfs(i);
		}
	}
}
void bfs(int x)
{
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		visited[front] = true;
		cout << front << ' ';
		
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && arr[front][i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}
int main()
{
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	dfs(V);
	cout << '\n';
	
	for (int i = 1; i <= N; i++)
		visited[i] = false;

	bfs(V);
	
	return 0;
}