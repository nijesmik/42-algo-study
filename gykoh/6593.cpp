#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int visited[30][30][30];
int building[30][30][30];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
	int L, R, C;
	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		queue<tuple<int, int, int, int>> q;
		for (int l = 0; l < L; l++)
		{
			for (int r = 0; r < R; r++)
			{
				for (int c = 0; c < C; c++)
				{
					char s;
					cin >> s;
					if (s == 'S')
					{
						q.push(make_tuple(l, r, c, 0));
						visited[l][r][c] = 1;
					}
					else if (s == 'E')
						building[l][r][c] = 2;
					else if (s == '#')
						building[l][r][c] = 1;
				}
			}
		}
		bool found = false;
		while (!q.empty() && !found)
		{
			tuple<int, int, int, int> front = q.front();
			q.pop();

			int x = get<0>(front);
			int y = get<1>(front);
			int z = get<2>(front);
			int steps = get<3>(front);
			if (building[x][y][z] == 2)
			{
				cout << "Escaped in " << steps << " minute(s)." << endl;
				found = true;
				break;
			}
			for (int i = 0; i < 6; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];
				if (nx >= 0 && nx < L && ny >= 0 && ny < R && nz >= 0 && nz < C &&
					building[nx][ny][nz] != 1 && !visited[nx][ny][nz])
				{
					visited[nx][ny][nz] = 1;
					q.push(make_tuple(nx, ny, nz, steps + 1));
				}
			}
		}
		if (!found)
			cout << "Trapped!" << endl;
		fill(&visited[0][0][0], &visited[0][0][0] + 30 * 30 * 30, 0);
	}
	return (0);
}
