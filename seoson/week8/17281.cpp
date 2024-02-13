#include <iostream>
using namespace std;
int N, ans;
int hit[50][9];
int base[3];
int order[9];
bool visited[9];
void calc()
{
	int score = 0;
	int hitter = 0;
	for (int i = 0; i < N; i++)
	{
		int out = 0;
		for (int j = 0; j < 3; j++)
			base[j] = 0;
		while (1)
		{
			if (hit[i][order[hitter]] == 0)
			{
				hitter++;
				if (hitter >= 9)
					hitter = 0;
				out++;
				if (out == 3)
					break;
			}
			else
			{
				if (hit[i][order[hitter]] == 1)
				{
					for (int j = 2; j >= 0; j--)
					{
						if (base[j])
						{
							if (j == 2)
							{
								base[j] = 0;
								score++;
							}
							else
							{
								base[j + 1] = 1;
								base[j] = 0;
							}
						}
					}
					base[0] = 1;
				}
				else if (hit[i][order[hitter]] == 2)
				{
					for (int j = 2; j >= 0; j--)
					{
						if (base[j])
						{
							if (j >= 1)
							{
								base[j] = 0;
								score++;
							}
							else
							{
								base[j + 2] = 1;
								base[j] = 0;
							}
						}
					}
					base[1] = 1;
				}
				else if (hit[i][order[hitter]] == 3)
				{
					for (int j = 2; j >= 0; j--)
					{
						if (base[j])
						{
							base[j] = 0;
							score++;
						}
					}
					base[2] = 1;
				}
				else
				{
					for (int j = 0; j < 3; j++)
					{
						if (base[j])
						{
							base[j] = 0;
							score++;
						}
					}
					score++;
				}
				hitter++;
				if (hitter >= 9)
					hitter = 0;
			}
		}
	}
	ans = max(ans, score);
}

void dfs(int depth)
{
	if (depth == 9)
	{
		calc();
		return;
	}
	for (int i = 0; i < 9; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			order[i] = depth;
			dfs(depth + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 9; j++)
			cin >> hit[i][j];
	visited[3] = true;
	order[3] = 0;
	dfs(1);
	cout << ans;
	return (0);
}