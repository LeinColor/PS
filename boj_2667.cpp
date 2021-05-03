#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[26][26];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool visited[26][26];
int index, order[1000], cnt;
int N;
struct Pos {
	int x, y;
};
int bfs(int x, int y)
{
	Pos pos = { x,y };
	int len = 0;

	queue<Pos> q;
	q.push(pos);
	visited[x][y] = true;

	while (!q.empty()) {
		int curr_x = q.front().x;
		int curr_y = q.front().y;
		len++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;

			if (!visited[nx][ny] && arr[nx][ny]) {
				Pos next_pos = { nx, ny };
				visited[nx][ny] = true;
				q.push(next_pos);
			}
		}
	}
	return len;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && arr[i][j]) {
				cnt++;
				order[index++] = bfs(i, j);
			}
		}
	}
	sort(order, order + index);
	printf("%d\n", cnt);
	for (int i = 0; i < index; i++)
		printf("%d\n", order[i]);
	
	return 0;
}