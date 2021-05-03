#include <iostream>
using namespace std;

char map[11][11];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	int rx, ry, bx, by;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R')
				rx = i; ry = j;
			if (map[i][j] == 'B')
				bx = i; by = j;
		}
	}

	
	return 0;
}