#include <iostream>
using namespace std;
int N, M, H, a, b;
bool ladder_pos[31][11];
int ladder_cnt;
bool is_answer = false;

void Input()
{
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		ladder_pos[a - 1][b] = true;
	}
}

void dfs(int y, int cnt)
{
    if (ladder_cnt == cnt)
	{
        bool is_possible = true;

		for (int i = 1; i <= N; i++)
		 {
            int vertical = i;

			for (int j = 0; j < H; j++)
			{
                int hight = j;

                if (ladder_pos[hight][vertical])
                    vertical++;
                else if (vertical > 1 && ladder_pos[hight][vertical - 1])
                    vertical--;
            }
            if (vertical != i)
			{
                is_possible = false;
                break;
            }
        }
        if (is_possible)
            is_answer = true;
        return;
    }

    for (int i = y; i < H; i++)
	{
        for (int j = 1; j < N; j++)
		{
            if (!ladder_pos[i][j-1] && !ladder_pos[i][j] && !ladder_pos[i][j+1])
			{
                ladder_pos[i][j] = true;
                dfs(i, cnt + 1);
                ladder_pos[i][j] = false;
            }
        }
    }
    return;
}

void Solution()
{
	for (int i = 0; i <= 3; i++)
	{
        ladder_cnt = i;
        dfs(0, 0);
        if (is_answer)
		{
            cout << ladder_cnt;
            return ;
        }
    }
    cout << -1;
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}