#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 501;
vector<int> edge[MAX_N];
vector<int> require_time;
int indegree[MAX_N];
int result[MAX_N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int time; cin >> time;
		require_time.push_back(time);
		result[i] = time;
		while (true) {
			int x; cin >> x;
			if (x == -1)
				break;
			edge[x - 1].push_back(i);
			indegree[i]++;
		}
	}
	
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int next : edge[curr]) {
			result[next] = max(result[next], result[curr] + require_time[next]);
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << result[i] << '\n';

	return 0;
}