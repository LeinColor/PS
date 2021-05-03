#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
int main()
{
	int N, K;
	cin >> N >> K;

	queue<pair<int, int> > q;
	q.push(make_pair(N, 0));
	visited[N] = true;
	while (!q.empty()) {
		int curr = q.front().first;
		int len = q.front().second;
		q.pop();
		if (curr == K) {
			cout << len;
			break;
		}

		if (curr - 1 >= 0 && !visited[curr - 1]) {
			visited[curr - 1] = true;
			q.push(make_pair(curr - 1, len + 1));
		}
		if (curr + 1 <= 100000 &&  !visited[curr + 1]) {
			visited[curr + 1] = true;
			q.push(make_pair(curr + 1, len + 1));
		}
		if (curr * 2 <= 100000 && !visited[curr * 2]) {
			visited[curr * 2] = true;
			q.push(make_pair(curr * 2, len + 1));
		}
	}
	return 0;
}