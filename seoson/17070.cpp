#include <iostream>
using namespace std;
int N,ans;
int dir1[3] = {0,1,1};
int dir2[3] = {1,0,1};
int board[20][20];
void	bfs(int x, int y, int dir);
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}
	bfs(0,1,0);
	cout << ans;
	return (0);
}

void	bfs(int x, int y, int dir)
{
	if (x == N - 1 && y == N - 1)
	{
		ans++;
		return ;
	}
	for (int i = 0; i < 3; i++)
	{
		if (dir == 0 && i == 1)
			continue ;
		if (dir == 1 && i == 0)
			continue ;
		int dx = x + dir1[i];
		int dy = y + dir2[i];
		if (dx < 0 || dy < 0 || dx >= N || dy >= N)
			continue ;
		if (board[dx][dy] == 1)
			continue ;
		if (i == 2 && (board[x][y + 1] == 1 || board[x + 1][y] == 1))
			continue ;
		bfs(dx,dy,i);
	}
}