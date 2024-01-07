#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> home;
vector<vector<int>> dp[3];

bool is_valid(int x, int y)
{
	if (x >= 0 && y >= 0 && x < N && y < N && home[x][y] == 0)
		return (true);
	return (false);
}

int main()
{
	cin >> N;
	home.resize(N, vector<int>(N));
	for (int i = 0; i < 3; i++)
		dp[i].resize(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> home[i][j];

	dp[0][0][1] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 2; j < N; j++)
		{
			if (is_valid(i, j))
			{
				if (is_valid(i, j - 1))
					dp[0][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];
				if (is_valid(i - 1, j))
					dp[1][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
				if (is_valid(i - 1, j) && is_valid(i, j - 1) && is_valid(i - 1, j - 1))
					dp[2][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
			}
		}
	}
	int sum = dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1];
	cout << sum << endl;
	return (0);
}
