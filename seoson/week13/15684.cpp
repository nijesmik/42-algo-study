#include <iostream>

using namespace std;
int N,M,H,cnt;
int board[31][31];
bool flag;

void dfs(int y, int depth)
{
	if (depth == cnt)
	{
		bool possible = true;
		for(int i = 1; i <= N; i++)
		{
			int vertical = i;
			for(int j = 0; j < H; j++)
			{
				int height = j;
				if (board[height][vertical])
					vertical++;
				else if (vertical > 1 && board[height][vertical - 1])
					vertical--;
			}
			if (vertical != i)
			{
				possible = false;
				break ;
			}
		}
		if (possible)
			flag = true;
		return ;
	}
	for(int i = y; i < H; i++)
	{
		for(int j = 1; j < N; j++)
		{
			if (!board[i][j - 1] && !board[i][j] && !board[i][j + 1])
			{
				board[i][j] = 1;
				dfs(i, depth + 1);
				board[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> N >> M >> H;
	int a,b;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		board[a - 1][b] = 1;
	}
	for(int i = 0; i <= 3; i++)
	{
		cnt = i;
		dfs(0,0);
		if (flag)
		{
			cout << cnt;
			return (0);
		}
	}
	cout << "-1";
	return (0);
}