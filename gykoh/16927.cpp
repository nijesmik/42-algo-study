#include <iostream>
#include <algorithm>
using namespace std;

int map[301][301];
int N,M,R;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
void rotate(int box)
{
	for (int i = 0; i < box; i++)
	{
		int start = map[i][i];
		int row = i;
		int col = i;
		int k = 0;
		while(k < 4)
		{
			int next_row = row + dr[k];
			int next_col = col + dc[k];
			if (next_row == i && next_col == i)
				break;
			if (i <= next_row && next_row < N - i && i <= next_col && next_col < M - i)
			{
				map[row][col] = map[next_row][next_col];
				row = next_row;
				col = next_col;
			}
			else
			{
				k++;
			}
		}
		map[i + 1][i] = start;
	}
}


int main()
{
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	int cnt = min(N, M) / 2;
	for (int i = 0; i < R; i++)
	{
		rotate(cnt);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j] << " ";
		}
		cout <<"\n";
	}
	return 0;
}
