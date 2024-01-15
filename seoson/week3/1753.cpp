#include <iostream>
#include <queue>
#define INF 2147483647

using namespace std;
int dist[20001]; //dist[1]은 시작점부터 node1까지의 최단거리 저장
vector <pair<int, int> > board[20001]; //[1]{5,2} = 노드1부터 2까지 5의 비용이든다.
priority_queue<pair<int, int> > q;
int V,E,K;
void dijkstra(int start);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int u,v,w;
	cin >> V >> E >> K;
	for (int i = 0 ; i < E; i++)
	{
		cin >> u >> v >> w;
		board[u].push_back(make_pair(w, v));
	}
	for (int i = 1 ; i < V + 1; i++)
		dist[i] = INF;
	dijkstra(K);
	for (int i = 1; i < V + 1; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	return (0);
}

void	dijkstra(int start)
{
	dist[start] = 0;
	q.push(make_pair(0, start));
	while (!q.empty())
	{
		int curr_node = q.top().second;
		int curr_dist = q.top().first;
		q.pop();
		if (dist[curr_node] < -curr_dist)
			continue ;
		for (int i = 0; i < board[curr_node].size(); i++)
		{
			int next_node = board[curr_node][i].second;
			int next_dist = -curr_dist + board[curr_node][i].first;
			if (dist[next_node] > next_dist)
			{
				dist[next_node] = next_dist;
				q.push(make_pair(-next_dist, next_node));
			}
		}
	}
}