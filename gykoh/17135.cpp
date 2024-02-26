#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int N, M, D;
int map[17][17];
int dx[3] = { -1,0,1 };
int dy[3] = { 0,-1,0 };
int ans;
queue<pair<int, int>> q;

void simulation(int x, int y, int z)
{
	int map_copy[17][17];
	bool check[16][16];
	bool visit[16][16];
	int archer[3] = { x,y,z };
	int pos = N + 1;
	int kill = 0;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			map_copy[i][j] = map[i][j];
			check[i][j] = false;
		}


	while (pos > 1)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= M; k++)
					visit[j][k] = false;

			q = queue<pair<int, int>>();
			int init_x = archer[i];
			int init_y = pos - 1;

			q.push({ init_x, init_y });

			while (!q.empty())
			{
				int now_x = q.front().first;
				int now_y = q.front().second;
				q.pop();

				visit[now_y][now_x] = true;

				if (map_copy[now_y][now_x] == 1)
				{
					check[now_y][now_x] = true;
					break;
				}

				for (int j = 0; j < 3; j++)
				{
					int next_x = now_x + dx[j];
					int next_y = now_y + dy[j];
					if (next_x >= 1 && next_x <= M && next_y >= 1 && next_y <= N)
						if ((abs(archer[i] - next_x) + abs(pos - next_y) <= D))
							if(!visit[next_y][next_x])
								q.push({ next_x, next_y });

				}
			}

		}

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (check[i][j])
					map_copy[i][j] = 0;


		pos--;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (check[i][j]) kill++;

	ans = max(ans, kill);
}

int main(void)
{
	cin >> N >> M >> D;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];

	for (int i = 1; i <= M; i++)
		for (int j = i + 1; j <= M; j++)
			for (int k = j + 1; k <= M; k++)
				simulation(i, j, k);

	cout << ans << '\n';
}
