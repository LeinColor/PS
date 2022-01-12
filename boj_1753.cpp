#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

using P = pair<int, int>;

const int MAX_V = 20001;
const int INF = 1'000'000'000;
vector<pair<int, int> > edge[MAX_V];
priority_queue<P, vector<P>, greater<P> > pq;
int dist[MAX_V];
bool visited[MAX_V];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int V, E, K;
	cin >> V >> E >> K;
	K--;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u - 1].push_back(make_pair(v - 1, w));
	}
	
	fill(dist, dist + MAX_V, INF);
	dist[K] = 0;
	pq.push(P(0, K));
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
				pq.push(P(dist[next], next));
			}
		}
	}

	for (int i = 0; i < V; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}