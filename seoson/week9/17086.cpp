#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int board[50][50];
int visited[50][50];
queue<pair<int, int>> q;
vector<int> vec;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int ans = 2147483647;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
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
			if (board[i][j] == 0)
			{
				q.push({i, j});
				int temp = 2147483647;
				for (int v_i = 0; v_i < 50; v_i++)
				{
					for (int v_j = 0; v_j < 50; v_j++)
						visited[v_i][v_j] = -1;
				}
				visited[i][j] = 0;
				while (!q.empty())
				{
					pair<int, int> curr = q.front();
					q.pop();
					for (int k = 0; k < 8; k++)
					{
						int nx = curr.first + dx[k];
						int ny = curr.second + dy[k];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M)
							continue;
						if (visited[nx][ny] != -1)
							continue;
						visited[nx][ny] = visited[curr.first][curr.second] + 1;
						if (board[nx][ny])
							temp = min(temp, visited[nx][ny]);
						else
							q.push({nx, ny});
					}
				}
				vec.push_back(temp);
			}
		}
	}
	sort(vec.rbegin(), vec.rend());
	cout << vec[0];
	return (0);
}