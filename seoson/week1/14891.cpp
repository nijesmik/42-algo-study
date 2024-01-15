#include <iostream>
#include <math.h>

using namespace std;
string gear[4];
int k, num, dir, ans;
void gear_rotate(int num, int dir);
void count_ans();

int main(void)
{
	for (int i = 0; i < 4; i++)
	{
		string input;
		cin >> input;
		gear[i] = input;
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> num >> dir;
		gear_rotate(num, dir);
	}
	count_ans();
	cout << ans;
	return (0);
}

void count_ans()
{
	for (int i = 0; i < 4; i++)
	{
		int a = 2;
		if (gear[i][0] == '1')
		{
			a = pow(a, i);
			ans += a;
		}
	}
}

void rotate_dir(int num, int dir)
{
	if (dir == 1)
	{
		string temp;
		temp += gear[num][7];
		for (int i = 0; i < 7; i++)
			temp += gear[num][i];
		gear[num] = temp;
	}
	else if (dir == -1)
	{
		string temp;
		char c = gear[num][0];
		for (int i = 1; i < 8; i++)
			temp += gear[num][i];
		temp += c;
		gear[num] = temp;
	}
}

void gear_rotate(int num, int dir)
{
	int check_rotate[4] = {0,};
	check_rotate[num - 1] = dir;
	for (int i = num; i < 4; i++)
	{
		if (gear[i][6] != gear[i - 1][2])
		{
			check_rotate[i] = check_rotate[i - 1] * -1;
		}
		else
			break ;
	}
	for (int i = num - 2; i >= 0; i--)
	{
		if (gear[i][2] != gear[i + 1][6])
			check_rotate[i] = check_rotate[i + 1] * -1;
		else
			break ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (check_rotate[i] != 0)
			rotate_dir(i, check_rotate[i]);
	}
}
