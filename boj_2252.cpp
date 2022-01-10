#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 32001;
vector<int> edge[MAX_N];
int indegree[MAX_N];
int result[MAX_N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		edge[A].push_back(B);
		indegree[B]++;
	}
	
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	for (int i = 0; i < N; i++) {
		int curr = q.front();
		q.pop();
		result[i] = curr;

		for (int next : edge[curr]) {
			if (--indegree[next] == 0)
				q.push(next);
		}
	}

	for (int i = 0; i < N; i++)
		cout << result[i] << ' ';

	return 0;
}