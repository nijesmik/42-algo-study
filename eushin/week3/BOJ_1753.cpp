#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 999999999

int V, E, K, u, v, w;
vector<pair<int, int>> graph[20001];
vector<int> dist(20001, INF);

void dijkstra()
{
	priority_queue <pair<int, int>> pq;

	dist[K] = 0;
	pq.push({0, K});

	while (pq.empty() == 0)
	{
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur_node].size(); i++) {
			int nxt_node = graph[cur_node][i].first;
			int nxt_dist = cur_dist + graph[cur_node][i].second;

			if (nxt_dist < dist[nxt_node]) {
				dist[nxt_node] = nxt_dist;
				pq.push({-nxt_dist, nxt_node});
			}
		}
	}
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E >> K;

	for (int i = 0; i < E; i++)
	{
		// u -> v 가는 가중치 w
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		if (u == v)
			graph[u].push_back({v, 0});
	}
	dijkstra();
	return 0;
}