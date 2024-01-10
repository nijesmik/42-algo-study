#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int x_dir[] = {0, 0, -1, 1};
	int y_dir[] = {-1, 1, 0, 0};
	int answer = 0;
	int N;

	cin >> N;
	vector<vector<int>> seats(N, vector<int>(N, 0));
	vector<vector<int>> likes(N * N + 1, vector<int>(4, 0));
	vector<int> students(N * N + 1);
	for (int i = 0; i < N * N; i++)
	{
		cin >> students[i];
		for (int j = 0; j < 4; j++)
			cin >> likes[students[i]][j];
	}
	for (int s = 0; s < N * N; s++)
	{
		int student = students[s];
		int max_adjacent = -1, max_empty = -1, seat_y = -1, seat_x = -1;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (seats[i][j] != 0)
					continue;
				int adjacent = 0, empty = 0;
				for (int dir = 0; dir < 4; dir++)
				{
					int dy = i + y_dir[dir], dx = j + x_dir[dir];
					if (dy >= N || dy < 0 || dx >= N || dx < 0)
						continue;
					if (seats[dy][dx] == 0)
					{
						empty++;
						continue;
					}
					for (int k = 0; k < 4; k++)
					{
						if (seats[dy][dx] == likes[student][k])
						{
							adjacent++;
							break;
						}
					}
				}
				if (adjacent > max_adjacent)
				{
					max_adjacent = adjacent, max_empty = empty;
					seat_y = i, seat_x = j;
				}
				else if (adjacent == max_adjacent)
				{
					if (empty > max_empty)
					{
						seat_y = i, seat_x = j;
						max_adjacent = adjacent, max_empty = empty;
					}
				}
				else
					continue;
			}
		seats[seat_y][seat_x] = student;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int student = seats[i][j];
			int liked_count = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int dy = i + y_dir[dir], dx = j + x_dir[dir];
				if (dy >= N || dy < 0 || dx >= N || dx < 0)
					continue;

				for (int k = 0; k < 4; k++)
				{
					if (seats[dy][dx] == likes[student][k])
					{
						liked_count++;
						break;
					}
				}
			}
			if (liked_count)
			{
				int score = 1;
				for (int s = 0; s < liked_count - 1; s++)
					score *= 10;
				answer += score;
			}
		}
	}
	cout << answer << endl;
	return 0;
}
