#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
using P = pair<int, int>;

const int MAX_V = 1001;
const int INF = 1'000'000'000;
vector<P> edge[MAX_V];
priority_queue<P, vector<P>, greater<P> > pq;
int dist[MAX_V];
bool visited[MAX_V];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u - 1].push_back(make_pair(v - 1, w));
	}

	fill(dist, dist + MAX_V, INF);

	int s, e;
	cin >> s >> e;
	s--, e--;
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curr]);
		
		if (visited[curr]) break;

		visited[curr] = true;
		for (auto& p : edge[curr]) {
			int next = p.first, d = p.second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	cout << dist[e];

	return 0;
}