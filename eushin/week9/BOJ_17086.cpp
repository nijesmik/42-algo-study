#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, answer;
int map[51][51];
bool visit[51][51];
vector <pair<int, int>> v;

// 좌상, 상, 우상, 좌, 우, 좌하, 하, 우하
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				v.push_back({i, j});
		}
	}
}

int bfs(int x, int y)
{
	queue <pair<pair<int, int>, int>> q;

	q.push({{x, y}, 0});
	visit[x][y] = true;

	while (true)
	{
		int r = q.front().first.first;
		int c = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (map[r][c] == 1)
			return cnt;
		for (int i = 0; i < 8; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < N && nc < M)
			{
				if (visit[nr][nc] == false)
				{
					visit[nr][nc] = true;
					q.push({{nr, nc}, cnt+1});
				}
			}
		}
	}
}

void Solution()
{
	for (int i = 0; i < v.size(); i++)
	{
		memset(visit, false, sizeof(visit));
		int r = v[i].first;
		int c = v[i].second;

		int safe_distance = bfs(r, c);
		answer = max(answer, safe_distance);
	}
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
