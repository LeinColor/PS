#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 300001;
int cards[MAX];
int N, M, answer;
void pick(int depth, int curr, int sum)
{
	if (depth == 3) {
		if (sum <= M) {
			answer = max(answer, sum);
		}
		return;
	}

	for (int i = curr; i < N; i++) {
		pick(depth + 1, i + 1, sum + cards[i]);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}
	pick(0, 0, 0);
	cout << answer;
	return 0;
}