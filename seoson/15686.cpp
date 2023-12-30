#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N,M,cnt,ans;
int board[51][51][2];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int> > _queue;

void	bfs_1()
{
	while (!_queue.empty())
	{
		pair<int,int> temp = _queue.front();
		_queue.pop();
		for (int i = 0; i < 4; i++)
		{
			int dir_x = dx[i] + temp.first;
			int dir_y = dy[i] + temp.second;
			if (dir_x >= N || dir_x <= -1 || dir_y >= N || dir_y <= -1)
				continue ;
			if (board[dir_x][dir_y][0] == 2)
			{
				cnt++;
				board[dir_x][dir_y][1]++;
				return ;
			}
			_queue.push(make_pair(dir_x, dir_y));
		}
	}
}

void	bfs_2()
{
	int distance = 0;
	while (!_queue.empty())
	{
		int size = _queue.size();
		distance++;
		for (int j = 0; j < size; j++)
		{
			pair<int,int> temp = _queue.front();
			_queue.pop();
			for (int i = 0; i < 4; i++)
			{
				int dir_x = dx[i] + temp.first;
				int dir_y = dy[i] + temp.second;
				if (dir_x >= N || dir_x <= -1 || dir_y >= N || dir_y <= -1)
					continue ;
				if (board[dir_x][dir_y][0] == 2)
				{
					ans += distance;
					while (!_queue.empty())
						_queue.pop();
					return ;
				}
				_queue.push(make_pair(dir_x, dir_y));
			}
		}
	}
}

void	del_chicken()
{
	int min_v = 2147483647;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j][0] == 2)
				min_v = min(min_v, board[i][j][1]);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j][0] == 2)
			{
				if (board[i][j][1] == min_v)
				{
					board[i][j][0] = 0;
					return ;
				}
			}
		}
	}
}

int main(void)
{
	int input;
	cin >> N >> M;
	for (int i = 0 ; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j][0];
			if (board[i][j][0] == 1)
				_queue.push(make_pair(i,j));
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j][0] == 1)
				bfs_1();
	int tmp = cnt - M;
	while (tmp-- > 0)
		del_chicken();
	while (!_queue.empty())
		_queue.pop();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j][0] == 1)
			{
				_queue.push(make_pair(i,j));
				bfs_2();
			}
		}
	}
	cout << ans;
	return (0);
}
