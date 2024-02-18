#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int result[51][10];
vector<vector<int>> cases;
int N, score;

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 9; j++)
			cin >> result[i][j];	// i번째 이닝의 j번 선수 결과
}

void GetCases()
{
	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

	do {
		int i = 1;
		for (auto e = v.begin(); e != v.end(); ++e)
		{
			if (i == 4 && *e == 1)
				cases.push_back(v);
			i++;
		}
	} while (next_permutation(v.begin(), v.end()));
}

void GetScore()
{
	bool base[4];
	for (auto it = cases.begin(); it != cases.end(); ++it)
	{
		int sum = 0;
		int start_player = 0;
		for (int inning = 1; inning <= N; inning++)
		{
			int out_count = 0;
			memset(base, false, sizeof(base));
			while (1)
			{
				if (out_count == 3)
					break;
				for (int num = start_player; num < 9; num++)
				{
					if (result[inning][(*it)[num]] == 1)
					{
						for (int x = 3; x > 0; x--)
						{
							if (base[x] == true)
							{
								if (x == 3)
								{
									base[x] = false;
									sum++;
								}
								else
								{
									base[x+1] = true;
									base[x] = false;
								}
							}
						}
						base[1] = true;
					}
					else if (result[inning][(*it)[num]] == 2)
					{
						for (int x = 3; x > 0; x--)
						{
							if (base[x] == true)
							{
								if (x == 3 || x == 2)
								{
									base[x] = false;
									sum++;
								}
								else
								{
									base[x+2] = true;
									base[x] = false;
								}
							}
						}
						base[2] = true;
					}
					else if (result[inning][(*it)[num]] == 3)
					{
						for (int x = 3; x > 0; x--)
						{
							if (base[x] == true)
							{
								base[x] = false;
								sum++;
							}
						}
						base[3] = true;
					}
					else if (result[inning][(*it)[num]] == 4)
					{
						for (int x = 3; x > 0; x--)
						{
							if (base[x] == true)
							{
								base[x] = false;
								sum++;
							}
						}
						sum++;
					}
					else if (result[inning][(*it)[num]] == 0)
						out_count++;
					if (out_count == 3)
					{
						start_player = (num + 1) % 9;
						break;
					}
					start_player = 0;
				}
			}
		}
		score = max(score, sum);
	}
}

void Solution()
{
	GetCases();
	GetScore();
	cout << score;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
