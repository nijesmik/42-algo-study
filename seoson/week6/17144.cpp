#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int R,C,T;
int arr[51][51];
queue<pair<int, int>> q;
queue<tuple<int, int, int>> q_2;
unsigned int ans;
int main()
{
	cin >> R >> C >> T;
	for(int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < T; i++)
	{
		int temp[51][51];
		for(int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				temp[i][j] = 0;
				if (arr[i][j] >= 5)
					q.push({i,j});
			}
		}
		while (!q.empty())
		{
			pair<int,int> curr = q.front();
			q.pop();
			int d = 0;
			for(int dir = 0; dir < 4; dir++)
			{
				int x = curr.first + dx[dir];
				int y = curr.second + dy[dir];
				if (x <= 0 || y <= 0 || x > R || y > C)
					continue ;
				if (arr[x][y] == -1)
					continue ;
				temp[x][y] += arr[curr.first][curr.second] / 5;
				d++;
			}
			q_2.push({curr.first, curr.second, d});
		}
		while (!q_2.empty())
		{
			tuple<int, int, int> curr = q_2.front();
			q_2.pop();
			arr[get<0>(curr)][get<1>(curr)] -= arr[get<0>(curr)][get<1>(curr)] / 5 * get<2>(curr);
		}
		int first_minus = 0;
		int second_minus = 0;
		for(int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				arr[i][j] += temp[i][j];
				if (first_minus == 0 && arr[i][j] == -1)
					first_minus = i;
				else if (first_minus != 0 && arr[i][j] == -1)
					second_minus = i;
			}
		}
		for(int i = first_minus - 1; i >= 1; i--)
		{
			if (arr[i + 1][1] == -1)
			{
				arr[i][1] = 0;
			}
			if (arr[i + 1][1] == 0)
			{
				arr[i + 1][1] = arr[i][1];
				arr[i][1] = 0;
			}
		}
		for(int i = 2; i <= C; i++)
		{
			if (arr[1][i - 1] == 0)
			{
				arr[1][i - 1] = arr[1][i];
				arr[1][i] = 0;
			}
		}
		for(int i = 2; i <= first_minus; i++)
		{
			if (arr[i - 1][C] == 0)
			{
				arr[i - 1][C] = arr[i][C];
				arr[i][C] = 0;
			}
		}
		for(int i = C; i > 2; i--)
		{
			if (arr[first_minus][i] == 0)
			{
				arr[first_minus][i] = arr[first_minus][i - 1];
				arr[first_minus][i - 1] = 0;
			}
		}
		for(int i = second_minus + 1; i <= R; i++)
		{
			if (arr[i - 1][1] == -1)
			{
				arr[i][1] = 0;
			}
			if (arr[i - 1][1] == 0)
			{
				arr[i - 1][1] = arr[i][1];
				arr[i][1] = 0;
			}
		}
		for(int i = 2; i <= C; i++)
		{
			if (arr[R][i - 1] == 0)
			{
				arr[R][i - 1] = arr[R][i];
				arr[R][i] = 0;
			}
		}
		for(int i = R - 1; i >= second_minus; i--)
		{
			if (arr[i + 1][C] == 0)
			{
				arr[i + 1][C] = arr[i][C];
				arr[i][C] = 0;
			}
		}
		for(int i = C - 1; i >= 2; i--)
		{
			if (arr[second_minus][i + 1] == 0)
			{
				arr[second_minus][i + 1] = arr[second_minus][i];
				arr[second_minus][i] = 0;
			}
		}
	}
	for(int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (arr[i][j] != -1)
				ans += arr[i][j];
		}
	}
	cout << ans;
	return (0);
}