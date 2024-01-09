#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

const int INF = 2147483647;
int dp[20001];
vector<pair<int, int>> vec[20001];

void dijkstra(int start)
{
    fill(dp, dp + 20001, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dp[start] = 0;
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();
        if (dp[vertex] < cost) 
            continue;
        for (pair<int, int> &edge : vec[vertex])
        {
            int next_vertex = edge.first;
            int new_cost = cost + edge.second;
            if (dp[next_vertex] > new_cost)
            {
                pq.push({new_cost, next_vertex}); 
                dp[next_vertex] = new_cost;
            }
        }
    }
}

int main()
{
	int V, E, K;
	cin >> V >> E >> K;
	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		vec[u].push_back({v, w});
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++)
	{
		if (dp[i] < INF)
			cout << dp[i] << '\n';
		else
			cout << "INF" << '\n';
	}
	return (0);
}
