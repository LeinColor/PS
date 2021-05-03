#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int M, N, len;
bool visited[1001][1001];
queue<pair<int, int> > q;
queue<int> ql;
void bfs()
{
	while (!q.empty()) {
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		len = ql.front();
		q.pop(); ql.pop();

		visited[curr_x][curr_y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (!visited[nx][ny] && arr[nx][ny] == 0) {
				visited[nx][ny] = true;
				arr[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				ql.push(len + 1);
			}
		}
	}
}
int main()
{
	cin >> M >> N;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			arr[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
				ql.push(0);
			}
		}
	}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << len;
	return 0;
}