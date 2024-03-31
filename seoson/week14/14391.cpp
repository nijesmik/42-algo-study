#include <iostream>

using namespace std;
int N,M;
int ans;
int board[4][4];

void solve()
{
	for(int i = 0; i < (1 << N * M); i++) //하나의 수라고 생각.
	{
		int sum = 0;
		//가로 종이조각 합
		for(int row = 0; row < N; row++)
		{
			int row_piece = 0;
			for(int col = 0; col < M; col++)
			{
				if ((i & (1 << row * M + col)) == 0) //0을 가로라고 생각
					row_piece = row_piece * 10 + board[row][col];
				else
				{
					 //세로를 만난경우 즉 1
					sum += row_piece;
					row_piece = 0;
				}
			}
			sum += row_piece;
		}
		//세로 종이조각 합
		for(int col = 0; col < M; col++)
		{
			int col_piece = 0;
			for(int row = 0; row < N; row++)
			{
				if ((i & (1 << row * M + col)) != 0) //세로인경우
					col_piece = col_piece * 10 + board[row][col];
				else
				{
					sum += col_piece;
					col_piece = 0;
				}
			}
			sum += col_piece;
		}
		ans = max(ans, sum);
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}
	solve();
	cout << ans;
	return (0);
}