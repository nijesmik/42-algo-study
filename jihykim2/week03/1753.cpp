#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

int                     V, E, Start;
vector<pair<int, int>>  Node[20001];    // "weight, destination" for priority queue
int                     Dist[20001];

static void dijkstra(void);

int main(void)
{
    cin >> V >> E >> Start;

    int n, destination, weight;
    for (int i = 0; i < E; i++)
    {
        cin >> n >> destination >> weight;
        Node[n].push_back(make_pair(weight, destination));
    }
    fill(Dist, Dist + V + 1, INF);

    dijkstra();

    for (int i = 1; i < V + 1; i++)
    {
        if (Dist[i] == INF)
            cout << "INF" << "\n";
        else
            cout << Dist[i] << "\n";
    }
    return 0;
}

static void dijkstra(void)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    Dist[Start] = 0;

    pq.push(make_pair(0, Start));
    while (pq.empty() == false)
    {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        for (int i = 0; i < Node[currNode].size(); i++)
        {
            int nextDist = currDist + Node[currNode][i].first;
            int nextNode = Node[currNode][i].second;

            if (nextDist < Dist[nextNode])
            {
                Dist[nextNode] = nextDist;
                pq.push(make_pair(nextDist, nextNode));
            }
        }
    }

}
