#include <iostream>
#include <vector>
using namespace std;
int N, M, u, v, idx, cnt;
int visit[1001];
vector<int> V[1001];

void DFS(int vertex)
{
    visit[vertex] = 1;
    for (int i = 0; i < V[vertex].size(); i++)
    {
        idx = V[vertex][i];
        if (visit[idx] == 0)
            DFS(idx);
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	while (M--)
	{
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}

    for (int i = 1; i <= N; i++)
    {
        if (visit[i] == 0)
        {
            cnt++;
            DFS(i);
        }
    }
    cout << cnt << "\n";
}
