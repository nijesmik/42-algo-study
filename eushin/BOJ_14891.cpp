#include <iostream>
#include <string>
using namespace std;
int gear[4][8];
string tmp;
int k, cur, nxt, prv, res;
int direction[101][2];
int check_diff[3];

void _is_diff()
{
	for (int i = 0; i < 3; i++)
		check_diff[i] = 0;
	if (gear[0][2] != gear[1][6])
		check_diff[0] = 1;
	if (gear[1][2] != gear[2][6])
		check_diff[1] = 1;
	if (gear[2][2] != gear[3][6])
		check_diff[2] = 1;
}

void clockwise(int gear[])
{
	cur = gear[0];
	prv = gear[7];
	gear[0] = prv;
	for (int i = 1; i < 8; i++)
	{
		prv = cur;
		cur = gear[i];
		gear[i] = prv;
	}
}

void counterclockwise(int gear[])
{
	cur = gear[7];
	nxt = gear[0];
	gear[7] = nxt;
	for (int i = 7; i > 0; i--)
	{
		nxt = cur;
		cur = gear[i - 1];
		gear[i - 1] = nxt;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++)
	{
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++)
		{
			int arg = tmp[j] - '0';
			gear[i][j] = arg;
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> direction[i][0] >> direction[i][1];

	for (int i = 0; i < k; i++)
	{
		_is_diff();
		if (direction[i][0] == 1) // 1번 톱니바퀴
		{
			if (direction[i][1] == 1) // 시계방향
			{
				clockwise(gear[0]);
				if (check_diff[0] == 1)
				{
					counterclockwise(gear[1]);
					if (check_diff[1] == 1)
					{
						clockwise(gear[2]);
						if (check_diff[2] == 1)
							counterclockwise(gear[3]);
					}
				}
			}
			else if (direction[i][1] == -1) // 반시계방향
			{
				counterclockwise(gear[0]);
				if (check_diff[0] == 1)
				{
					clockwise(gear[1]);
					if (check_diff[1] == 1)
					{
						counterclockwise(gear[2]);
						if (check_diff[2] == 1)
							clockwise(gear[3]);
					}
				}
			}
		}
		if (direction[i][0] == 2) // 2번 톱니바퀴
		{
			if (direction[i][1] == 1) // 시계방향
			{
				clockwise(gear[1]);
				if (check_diff[0] == 1)
					counterclockwise(gear[0]);
				if (check_diff[1] == 1)
				{
					counterclockwise(gear[2]);
					if (check_diff[2] == 1)
						clockwise(gear[3]);
				}
			}
			else if (direction[i][1] == -1) // 반시계방향
			{
				counterclockwise(gear[1]);
				if (check_diff[0] == 1)
					clockwise(gear[0]);
				if (check_diff[1] == 1)
				{
					clockwise(gear[2]);
					if (check_diff[2] == 1)
						counterclockwise(gear[3]);
				}
			}
		}
		if (direction[i][0] == 3) // 3번 톱니바퀴
		{
			if (direction[i][1] == 1) // 시계방향
			{
				clockwise(gear[2]);
				if (check_diff[1] == 1)
				{
					counterclockwise(gear[1]);
					if (check_diff[0] == 1)
						clockwise(gear[0]);
				}
				if (check_diff[2] == 1)
					counterclockwise(gear[3]);
			}
			else if (direction[i][1] == -1) // 반시계방향
			{
				counterclockwise(gear[2]);
				if (check_diff[1] == 1)
				{
					clockwise(gear[1]);
					if (check_diff[0] == 1)
						counterclockwise(gear[0]);
				}
				if (check_diff[2] == 1)
					clockwise(gear[3]);
			}
		}
		if (direction[i][0] == 4) // 4번 톱니바퀴
		{
			if (direction[i][1] == 1) // 시계방향
			{
				clockwise(gear[3]);
				if (check_diff[2] == 1)
				{
					counterclockwise(gear[2]);
					if (check_diff[1] == 1)
					{
						clockwise(gear[1]);
						if (check_diff[0] == 1)
							counterclockwise(gear[0]);
					}
				}
			}
			else if (direction[i][1] == -1) // 반시계방향
			{
				counterclockwise(gear[3]);
				if (check_diff[2] == 1)
				{
					clockwise(gear[2]);
					if (check_diff[1] == 1)
					{
						counterclockwise(gear[1]);
						if (check_diff[0] == 1)
							clockwise(gear[0]);
					}
				}
			}
		}
	}
	if (gear[0][0] == 1)
		res += 1;
	if (gear[1][0] == 1)
		res += 2;
	if (gear[2][0] == 1)
		res += 4;
	if (gear[3][0] == 1)
		res += 8;
	cout << res;
}