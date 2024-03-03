#include <iostream>

using namespace std;
int N, M, ans;
int board[500][500];
bool visited[500][500];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dfs(int x, int y, int depth, int score)
{
	if (depth == 3)
	{
		ans = max(ans, score);
		return;
	}
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		if (visited[nx][ny])
			continue;
		visited[nx][ny] = true;
		dfs(nx, ny, depth + 1, score + board[nx][ny]);
		visited[nx][ny] = false;
	}
	if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < N)
		ans = max(ans, (board[x - 1][y] + board[x][y - 1] + board[x + 1][y] + board[x][y]));
	if (x - 1 >= 0 && y + 1 <= M && x + 1 < N)
		ans = max(ans, (board[x - 1][y] + board[x][y + 1] + board[x + 1][y] + board[x][y]));
	if (y - 1 >= 0 && y + 1 <= M && x + 1 < N)
		ans = max(ans, (board[x][y - 1] + board[x][y + 1] + board[x + 1][y] + board[x][y]));
	if (y - 1 >= 0 && y + 1 <= M && x + 1 < N)
		ans = max(ans, (board[x + 1][y - 1] + board[x + 1][y + 1]+ board[x + 1][y] + board[x][y]));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = true;
			dfs(i, j, 0, board[i][j]);
			visited[i][j] = false;
		}
	}
	cout << ans;
	return (0);
}