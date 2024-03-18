#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[100][100];
bool visited_c[100][100];
int visited[100][100];
int N, c_cnt;
int ans = 2147483647;
queue<pair<int, int>> q;

void bfs_country(int i, int j, int c)
{
	q.push({i, j});
	visited_c[i][j] = true;
	board[i][j] = c;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (visited_c[nx][ny] || board[nx][ny] == 0)
				continue;
			visited_c[nx][ny] = true;
			board[nx][ny] = c;
			q.push({nx, ny});
		}
	}
}

void bfs_bridge(int i, int j, int c)
{
	while(!q.empty())
		q.pop();
	for (int k = 0; k < N; k++)
	{
		for (int l = 0; l < N; l++)
			visited[k][l] = 0;
	}
	q.push({i, j});
	visited[i][j] = 1;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (board[nx][ny] == c || visited[nx][ny] != 0)
				continue;
			if (board[nx][ny] != 0 && board[nx][ny] != c)
			{
				ans = min(ans, visited[cur.first][cur.second] - 1);q.emplace();
				return;
			}
			visited[nx][ny] = visited[cur.first][cur.second] + 1;
			q.push({nx, ny});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 1 && !visited_c[i][j])
			{
				c_cnt--;
				bfs_country(i, j, c_cnt);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] != 0)
				bfs_bridge(i, j, board[i][j]);
		}
	}
	cout << ans;
	return (0);
}