#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, cnt;
int size = 1;
int paper[501][501];
bool visited[501][501];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<int> v;
queue<pair<int, int>> q;

void FindDrawing(int r, int c)
{
	visited[r][c] = true;
	q.push({r, c});
	while (q.empty() == false)
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m)
				continue ;
			if (paper[nr][nc] == 1 && visited[nr][nc] == false)
			{
				visited[nr][nc] = true;
				size++;
				q.push({nr, nc});
			}
		}
	}
}

void Solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (paper[i][j] == 1 && visited[i][j] == false)
			{
				FindDrawing(i, j);
				v.push_back(size);
				cnt++;
				size = 1;
			}
		}
	}
	sort(v.begin(), v.end(), greater<int>());
	cout << cnt << "\n";
	if (cnt == 0)
		cout << 0;
	else
		cout << v[0];
}

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}