#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int M, N, K;
int board[101][101];
bool visited[101][101];
queue<pair<int, int>> q;
vector<int> vec;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y)
{
	q.push({x, y});
	visited[x][y] = true;
	int ret = 0;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		ret++;
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (visited[nx][ny] || board[nx][ny])
				continue;
			visited[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	vec.push_back(ret);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x1, y1, x2, y2;
	cin >> M >> N >> K;
	while (K--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
				board[i][j] = 1;
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!board[i][j] && !visited[i][j])
				bfs(i, j);
		}
	}
	sort(vec.begin(),vec.end());
	cout << vec.size() << "\n";
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	return (0);
}