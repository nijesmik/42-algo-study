#include <iostream>
using namespace std;
int N, M, x, y, K;
int map[21][21];
int dir[1001];
int row[4], col[4];

void Input()
{
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	for (int i = 0; i < K; i++)
		cin >> dir[i];
}

void Solution()
{
	int r = x;
	int c = y;
	for (int i = 0; i < K; i++)
	{
		if (dir[i] == 1 && c <= M - 2)
		{
			row[3] = row[2]; row[2] = row[1]; row[1] = row[0]; row[0] = col[3];
			col[1] = row[1]; col[3] = row[3];
			c++;
		}
		else if (dir[i] == 2 && c >= 1)
		{
			row[3] = row[0]; row[0] = row[1]; row[1] = row[2]; row[2] = col[3];
			col[1] = row[1]; col[3] = row[3];
			c--;
		}
		else if (dir[i] == 3 && r >= 1)
		{
			col[3] = col[0]; col[0] = col[1]; col[1] = col[2]; col[2] = row[3];
			row[1] = col[1]; row[3] = col[3];
			r--;
		}
		else if (dir[i] == 4 && r <= N - 2)
		{
			col[3] = col[2]; col[2] = col[1]; col[1] = col[0]; col[0] = row[3];
			row[1] = col[1]; row[3] = col[3];
			r++;
		}
		else
			continue;
		if (map[r][c] == 0)
			map[r][c] = row[3];
		else
		{
			row[3] = map[r][c];
			col[3] = map[r][c];
			map[r][c] = 0;
		}
		cout << col[1] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}