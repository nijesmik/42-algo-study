#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N,M,V;
int board[1001][1001];
bool visited[1001];
queue<int> q;
vector<int> dfs_vec;
vector<int> bfs_vec;

void dfs(int v)
{
	visited[v] = true;
	dfs_vec.push_back(v);
	for(int i = 1; i <= N; i++)
	{
		if (!visited[i] && (board[v][i] || board[i][v]))
			dfs(i);
	}
}

void bfs(int v)
{
	q.push(v);
	visited[v] = true;
	bfs_vec.push_back(v);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int i = 1; i <= N; i++)
		{
			if (!visited[i] && (board[cur][i] || board[i][cur]))
			{
				q.push(i);
				bfs_vec.push_back(i);
				visited[i] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> N >> M >> V;
	for(int i = 0; i < M; i++)
	{
		int P,V;
		cin >> P >> V;
		board[P][V] = true;
		board[V][P] = true;
	}
	dfs(V);
	memset(visited, 0, sizeof(visited));
	bfs(V);
	for(int i = 0; i < dfs_vec.size(); i++)
	{
		cout << dfs_vec[i];
		if (i != dfs_vec.size() - 1)
			cout << " ";
	}
	cout << "\n";
	for(int i = 0; i < bfs_vec.size(); i++)
	{
		cout << bfs_vec[i];
		if (i != bfs_vec.size() - 1)
			cout << " ";
	}
	return (0);
}