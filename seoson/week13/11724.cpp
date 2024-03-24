#include <iostream>
#include <queue>
using namespace std;
int N,M,cnt;
int board[1001][1001];
bool visited[1001];
queue<int> q;
void bfs(int i)
{
	visited[i] = true;
	q.push(i);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int j = 1; j <= N; j++)
		{
			if (!board[cur][j])
				continue;
			if (visited[j])
				continue;
			visited[j] = true;
			q.push(j);
		}
	}
	cnt++;
}

int main()
{
	int u,v;
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		cin >> u >> v;
		board[u][v] = 1;
		board[v][u] = 1;
	}
	for(int i = 1; i <= N; i++)
	{
		if (!visited[i])
			bfs(i);
	}
	cout << cnt;
	return (0);
}