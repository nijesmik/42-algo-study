#include <iostream>

using namespace std;

#define HOR	1	// 가로
#define VER	2	// 세로
#define DIA	3	// 대각선

int	N, cnt;
int	home[16][16];

static void	_go_next(int x, int y, int type);

int	main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> home[i][j];

	_go_next(0, 1, HOR);

	cout << cnt;

	return 0;
}

static void	_go_next(int x, int y, int type)
{
	if (x == N - 1 && y == N - 1)
	{
		cnt++;
		return ;
	}
	else if (x > N - 1 || y > N - 1 || home[x][y] == 1)
		return ;

	if (type == HOR && y + 1 < N && home[x][y + 1] == 0)
		_go_next(x, y + 1, HOR);
	else if (type == VER && x + 1 < N && home[x + 1][y] == 0)
		_go_next(x + 1, y, VER);
	else if (type == DIA)
	{
		if (y + 1 < N && home[x][y + 1] == 0)
			_go_next(x, y + 1, HOR);
		if (x + 1 < N && home[x + 1][y] == 0)
			_go_next(x + 1, y, VER);
	}
	if (y + 1 < N && x + 1 < N && home[x + 1][y + 1] == 0 && home[x][y + 1] == 0 && home[x + 1][y] == 0)
		_go_next(x + 1, y + 1, DIA);
}














// static void	_dfs(int x, int y, int** home, int type)
// {
// 	if (x == N - 1 && y == N - 1)
// 	{
// 		cnt++;
// 		return ;
// 	}

// }


/*
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/
