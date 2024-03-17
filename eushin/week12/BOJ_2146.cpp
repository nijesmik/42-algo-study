#include <iostream>
#include <queue>
using namespace std;

int N, cnt;
int board[100][100];
int visited[100][100];
int dist[100][100];
queue<pair<int, int>> land[5001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
}

int FindLand()
{
    int landCnt = 0;
    for (int i = 0; i < N; i++)
	{
        for (int j = 0; j < N; j++)
		{
            if (board[i][j] == 0 || visited[i][j])
				continue;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            visited[i][j] = ++landCnt;

			while (!Q.empty())
			{
				int curX = Q.front().first;
				int curY = Q.front().second;
                Q.pop();
                bool isBorder = false;
                for (int d = 4; d--;)
				{
                    int nx = curX + dx[d];
					int ny = curY + dy[d];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;
                    if (visited[nx][ny])
						continue;
                    if (board[nx][ny] == 0)
					{
                        isBorder = true;
                        continue;
                    }
                    visited[nx][ny] = landCnt;
                    Q.push({nx, ny});
                }
                if (isBorder)
					land[landCnt].push({curX, curY});
            }
        }
    }
    return landCnt;
}

int MakeBridge(int landNum)
{
	queue<pair<int, int>> Q = land[landNum];

    while(!Q.empty())
	{
		int curX = Q.front().first;
		int curY = Q.front().second;
        for (int d = 4; d--;)
		{
            int nx = curX + dx[d];
			int ny = curY + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
            if (visited[nx][ny] == landNum)
				continue;
            if (board[nx][ny] == 0)
			{
                visited[nx][ny] = landNum;
                dist[nx][ny] = dist[curX][curY] + 1;
                Q.push({nx, ny});
            }
            else
				return dist[curX][curY];
        }
    }
    return 200;
}

void Solution()
{
	cnt = FindLand();
    int ans = 200;
    for (int i = 1; i <= cnt; i++)
        ans = min(ans, MakeBridge(i));
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
