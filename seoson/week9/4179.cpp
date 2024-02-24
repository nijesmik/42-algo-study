#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string	board[1001];
queue<pair<int, int> > q_fire;
queue<pair<int, int> > q_ji;
int visited_fire[1001][1001];
int visited_ji[1001][1001];
int R,C;
int main()
{
	cin >> R >> C;
	for(int i = 0; i < R; i++)
		cin >> board[i];
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if (board[i][j] == 'J')
			{
				q_ji.push({i,j});
				visited_ji[i][j] = 1;
			}
			else if (board[i][j] == 'F')
			{
				q_fire.push({i,j});
				visited_fire[i][j] = 1;
			}
		}
	}
	while(!q_fire.empty())
	{
		pair<int, int> curr = q_fire.front();
		q_fire.pop();
		for(int i = 0; i < 4; i++)
		{
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue ;
			if (board[nx][ny] == '#')
				continue ;
			if (visited_fire[nx][ny] != 0)
				continue ;
			visited_fire[nx][ny] = visited_fire[curr.first][curr.second] + 1;
			q_fire.push({nx,ny});
		}
	}
	while (!q_ji.empty())
	{
		pair<int, int> curr = q_ji.front();
		q_ji.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			{
				cout << visited_ji[curr.first][curr.second];
				return (0);
			}
			if (board[nx][ny] == '#' || visited_ji[nx][ny] != 0)
				continue ;
			if (visited_fire[nx][ny] != 0 && visited_fire[nx][ny] <= visited_ji[curr.first][curr.second] + 1)
				continue ;
			visited_ji[nx][ny] = visited_ji[curr.first][curr.second] + 1;
			q_ji.push({nx,ny});
		}
	}
	cout << "IMPOSSIBLE";
	return (0);
}