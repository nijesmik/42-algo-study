#include <iostream>
using namespace std;
int N, cnt;
int map[16][16];
int dx[3] = {0, 1, 1};	// 가로, 세로, 대각선
int dy[3] = {1, 0, 1};

void find_road(int x, int y, int dir) // dir : 0 -> 가로, 1 -> 세로, 2 -> 대각선
{
	if (x == N - 1 && y == N - 1)
	{
		cnt++;
		return ;
	}
	for (int i = 0; i < 3; i++)
	{
		if ((dir == 0 && i == 1) || (dir == 1 && i == 0)) // 가로 -> 세로 || 세로 -> 가로 안됨
			continue;
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N)
			continue;
		if (i == 2 && (map[x + 1][y] == 1 || map[x][y + 1] == 1))
			continue;
		if (i < 2 && map[next_x][next_y] == 0)
			find_road(next_x, next_y, i);
		else if (i == 2 && !map[next_x][next_y] && !map[next_x - 1][next_y] && !map[next_x][next_y - 1])
			find_road(next_x, next_y, i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> map[r][c];

	find_road(0, 1, 0); // (1, 0)에서 시작
	cout << cnt;
}