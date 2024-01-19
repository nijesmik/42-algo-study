#include <iostream>
#include <queue>
using namespace std;
int board[501][501];
bool visited[501][501] = {false, };
queue<pair<int, int>> q;
int n,m,ans,mx;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main()
{
	int area;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> board[i][j];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && visited[i][j] != true)
			{
				area = 0;
				q.push({i, j});
				visited[i][j] = true;
				ans++;
			}
			while (!q.empty())
			{
				pair<int, int> curr = q.front();
				q.pop();
				area++;
				for (int i = 0; i < 4; i++)
				{
					int nx = curr.first + dx[i];
					int ny = curr.second + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)
						continue ;
					if (visited[nx][ny] == true || board[nx][ny] == 0)
						continue ;
					visited[nx][ny] = true;
					q.push({nx,ny});
				}
				mx = max(mx, area);
			}
		}
	}
	cout << ans << "\n" << mx;
	return (0);
}