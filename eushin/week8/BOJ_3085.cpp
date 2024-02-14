#include <iostream>
#include <algorithm>
using namespace std;

int N, Max;
char board[51][51];

void check_row(int N)
{
	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == board[i][j+1])
				cnt++;
			else
			{
				Max = max(Max, cnt);
				cnt = 1;
			}
			Max = max(Max, cnt);
		}
	}
}

void check_col(int N)
{
	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[j][i] == board[j+1][i])
				cnt++;
			else
			{
				Max = max(Max, cnt);
				cnt = 1;
			}
			Max = max(Max, cnt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j + 1 < N; j++)
		{
			swap(board[i][j], board[i][j+1]);
			check_row(N);
			check_col(N);
			swap(board[i][j], board[i][j+1]);

			swap(board[j][i], board[j+1][i]);
			check_row(N);
			check_col(N);
			swap(board[j][i], board[j+1][i]);
		}
	}
	cout << Max;
}