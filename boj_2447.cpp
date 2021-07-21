#include <iostream>
using namespace std;

char arr[2189][2189];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
void square(int N, int x, int y)
{
	if (N == 3) {
		for (int i = 0; i < 8; i++)
			arr[x + dx[i]][y + dy[i]] = '*';
		return;
	}
	square(N / 3, x - N / 3, y - N / 3);
	square(N / 3, x - N / 3, y);
	square(N / 3, x - N / 3, y + N / 3);

	square(N / 3, x, y - N / 3);
	square(N / 3, x, y + N / 3);

	square(N / 3, x + N / 3, y - N / 3);
	square(N / 3, x + N / 3, y);
	square(N / 3, x + N / 3, y + N / 3);
}
int main()
{
	int N;
	cin >> N;
	square(N, N / 2, N / 2);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '*')
				putchar('*');
			else
				putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}