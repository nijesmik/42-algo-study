#include <iostream>

using namespace std;
int N, ans;
string str[50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void calc(int ny, int nx, int i, int j)
{
	string temp[50];
	for (int i = 0; i < N; i++)
		temp[i] = str[i];
	char d = temp[i][j];
	temp[i][j] = temp[ny][nx];
	temp[ny][nx] = d;
	char c;
	int cnt;
	for (int i = 0; i < N; i++)
	{
		c = temp[i][0];
		cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (temp[i][j] != c)
			{
				ans = max(ans, cnt);
				cnt = 1;
				c = temp[i][j];
			}
			else
				cnt++;
		}
		ans = max(ans,cnt);
	}
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		c = temp[0][i];
		for (int j = 0; j < N; j++)
		{
			if (temp[j][i] != c)
			{
				ans = max(ans, cnt);
				cnt = 1;
				c = temp[j][i];
			}
			else
				cnt++;
		}
		ans = max(ans,cnt);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> str[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = j + dx[dir];
				int ny = i + dy[dir];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				calc(ny, nx, i, j);
			}
		}
	}
	cout << ans;
	return (0);
}