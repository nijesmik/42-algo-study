#include <iostream>

using namespace std;
int N,M,cnt;
int board[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
			cin >> board[i][j];
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			for(int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if(nx < 0 || ny < 0 || nx >= N || ny >= M)
				{
					cnt += board[i][j];
					continue;
				}
				else if (board[i][j] > board[nx][ny])
				{
					cnt += board[i][j] - board[nx][ny];
				}
			}
		}
	}
	cnt += N * M * 2;
	cout << cnt;
	return (0);
}