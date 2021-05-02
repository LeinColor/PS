#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[101][101];
bool visited[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
struct P {
	int x;
	int y;
	int l;
};
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	
	queue<P> q;
	P p{ 0,0,1 };
	q.push(p);
	while (!q.empty()) {
		int curr_x = q.front().x;
		int curr_y = q.front().y;
		int curr_l = q.front().l;
		q.pop();
		visited[curr_x][curr_y] = true;

		if (curr_x == N - 1 && curr_y == M - 1) {
			cout << curr_l;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];

			if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)
				continue;

			if (!visited[next_x][next_y] && arr[next_x][next_y]) {
				visited[next_x][next_y] = true;
				P a{ curr_x + dx[i], curr_y + dy[i], curr_l + 1 };
				q.push(a);
			}
		}
	}
	return 0;
}