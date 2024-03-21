#include <iostream>
#include <cstring>

using namespace std;

void dfs(int now);

int map[1001][1001];
int visited[500000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, x, y, cnt = 0;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0){
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}

void dfs(int now)
{
	for (int i = 0; i < 1001; i++)
	{
		if (map[now][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1;
			dfs(i);
		}
	}
	
}
