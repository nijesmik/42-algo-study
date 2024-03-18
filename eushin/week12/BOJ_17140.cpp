#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k, ans;
int board[101][101];
int counter[101];

void Input()
{
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];
}

void Find()
{
	int height = 3, width = 3, time = 0;

	while (true)
	{
		if (board[r][c] == k)
		{
			ans = time;
			break;
		}
		if (time > 100)
		{
			ans = -1;
			break;
		}

		if (height >= width)
		{
			int max_len = 0;
			for (int i = 1; i <= height; i++)
			{
				memset(counter, 0, sizeof(counter));
				vector<pair<int, int>> v;

				for (int j = 1; j <= width; j++)
					counter[board[i][j]]++;
				for (int j = 1; j < 101; j++)
					if (counter[j])
						v.push_back({ counter[j], j });
				int len = v.size();
				max_len = max(max_len, len * 2);
				sort(v.begin(), v.end());
				for (int j = 1; j < 101; j++)
					board[i][j] = 0;
				int idx = 1;
				for (int j = 0; j < len; j++)
				{
					board[i][idx++] = v[j].second;
					board[i][idx++] = v[j].first;
				}
			}
			width = max_len;
		}
		else
		{
			int max_len = 0;
			for (int i = 1; i <= width; i++)
			{
				memset(counter, 0, sizeof(counter));
				vector<pair<int, int>> v;

				for (int j = 1; j <= height; j++)
					counter[board[j][i]]++;
				for (int j = 1; j < 101; j++)
					if (counter[j])
						v.push_back({ counter[j], j });
				int len = v.size();
				max_len = max(max_len, len * 2);
				sort(v.begin(), v.end());
				for (int j = 1; j < 101; j++)
					board[j][i] = 0;
				int idx = 1;
				for (int j = 0; j < len; j++)
				{
					board[idx++][i] = v[j].second;
					board[idx++][i] = v[j].first;
				}
			}
			height = max_len;
		}
		time++;
	}
}

void Solution()
{
	if (board[r][c] == k)
	{
		cout << 0;
		return;
	}
	Find();
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}