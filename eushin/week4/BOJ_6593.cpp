#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
using namespace std;
int L, R, C;
int start_x, start_y, start_z;
char building[31][31][31];
bool visit[31][31][31];
int dx[] = {1,-1,0,0,0,0}; // 동서남북상하
int dy[] = {0,0,-1,1,0,0};
int dz[] = {0,0,0,0,1,-1};
vector<int> result;
bool found = false;

void bfs(int x1, int y1,int z1, int c1)
{
	queue<tuple<int, int, int, int>> q;
	q.push(make_tuple(x1, y1, z1, c1));
	visit[z1][y1][x1] = true;

	while (q.empty() != true)
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		int cnt = get<3>(q.front());
		if (building[z][y][x] == 'E')
		{
			found = true;
			result.push_back(cnt);
			break;
		}
		q.pop();
		for (int i = 0; i < 6;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < C && ny < R && nz < L)
			{
				if (visit[nz][ny][nx] == false && building[nz][ny][nx] != '#')
				{
					q.push(make_tuple(nx, ny, nz, cnt + 1));
					visit[nz][ny][nx] = true;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		memset(visit, false, sizeof(visit));
		found = false;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S')
					{
						start_x = k;
						start_y = j;
						start_z = i;
					}
				}
			}
		}
		bfs(start_x, start_y, start_z, 0);
		if (found == false)
			result.push_back(-1);
	}
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] == -1)
			cout << "Trapped!" << '\n';
		else
			cout << "Escaped in " << result[i] << " minute(s)." << '\n';
	}
}