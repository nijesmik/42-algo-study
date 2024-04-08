#include <iostream>
#include <queue>
using namespace std;
int N, M, H, W, Sr, Sc, Fr, Fc, cnt;
int board[1001][1001];
int visited[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool can_move(int x, int y, int dir)
{
	if (dir == 0) // 아래
	{
		int temp = y + W - 1;
		if (temp > M)
			return false;
		for (int i = x; i < x + H; i++)
		{
			if (board[i][temp] == 1)
				return false;
		}
	}
	else if (dir == 1) // 위
	{
		for (int i = x; i < x + H; i++)
		{
			if (board[i][y] == 1)
				return false;
		}
	}
	else if (dir == 2) // 오른쪽
	{
		int temp = x + H - 1;
		if (temp > N)
			return false;
		for (int i = y; i < y + W; i++)
		{
			if (board[temp][i] == 1)
				return false;
		}
	}
	else if (dir == 3) // 왼쪽
	{
		for (int i = y; i < y + W; i++)
		{
			if (board[x][i] == 1)
				return false;
		}
	}
	return true;
}

queue<pair<int, int>> q;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
			visited[i][j] = -1;
	}
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
	}
	cin >> H >> W;
	cin >> Sr >> Sc >> Fr >> Fc;
	q.push({Sr, Sc});
	visited[Sr][Sc] = 1;
	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();
		if (curr.first == Fr && curr.second == Fc)
		{
			cout << visited[curr.first][curr.second] - 1;
			return (0);
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];
			if (nx < 1 || ny < 1 || nx > N || ny > M)
				continue;
			if (board[nx][ny] == 1 || visited[nx][ny] != -1)
				continue;
			if (!can_move(nx, ny, i))
				continue;
			visited[nx][ny] = visited[curr.first][curr.second] + 1;
			q.push({nx, ny});
		}
	}
	cout << "-1";
	return (0);
}