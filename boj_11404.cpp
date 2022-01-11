#include <iostream>
using namespace std;

const int INF = 10000001;
const int MAX_N = 101;
int result[MAX_N][MAX_N];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) result[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (result[a - 1][b - 1] > c)
			result[a - 1][b - 1] = c;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (result[k][j] > result[k][i] + result[i][j]) {
					result[k][j] = result[k][i] + result[i][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (result[i][j] == INF) cout << "0 ";
			else cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}