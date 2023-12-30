#include <iostream>
using namespace std;
int R, C;
string map[500];
bool is_wolf, is_sheep;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> map[i];
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'W')
				is_wolf = 1;
			else if (map[i][j] == 'S')
				is_sheep = 1;
		}
	}
	if ((is_sheep == 1 && is_wolf == 0) || (is_sheep == 0 && is_wolf == 1))
	{
		cout << 1 << "\n";
		for (int i = 0; i < R; i++)
			cout << map[i] << "\n";
		return 0;
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'S')
			{
				// 상
				if (i > 0 && map[i - 1][j] == '.')
					map[i - 1][j] = 'D';
				else if (i > 0 && map[i - 1][j] == 'W')
				{
					cout << 0;
					return 0;
				}
				// 하
				if (i < R - 1 && map[i + 1][j] == '.')
					map[i + 1][j] = 'D';
				else if (i < R - 1 && map[i + 1][j] == 'W')
				{
					cout << 0;
					return 0;
				}
				// 좌
				if (j > 0 && map[i][j - 1] == '.')
					map[i][j - 1] = 'D';
				else if (j > 0 && map[i][j - 1] == 'W')
				{
					cout << 0;
					return 0;
				}
				// 우
				if (j < C - 1 && map[i][j + 1] == '.')
					map[i][j + 1] = 'D';
				else if (j < C - 1 && map[i][j + 1] == 'W')
				{
					cout << 0;
					return 0;
				}
			}
		}
	}
	cout << 1 << "\n";
	for (int i = 0; i < R; i++)
		cout << map[i] << "\n";
}