#include <iostream>
#include <deque>
#include <utility>
using namespace std;
int N, K, tmp, cycle_cnt;
deque <pair<int, bool>> A_top, A_bot;

void put_robot(void)
{
	if (A_top[0].first >= 1)
	{
		A_top[0].first--;
		A_top[0].second = true;
	}
	A_top[N - 1].second = false;
}

void move_robot(void)
{
	for (int i = N - 2; i >= 0; i--)
	{
		if (A_top[i].second == true && A_top[i + 1].second == false && A_top[i + 1].first >= 1)
		{
			A_top[i].second = false;
			A_top[i + 1].second = true;
			A_top[i + 1].first--;
			A_top[N - 1].second = false;
		}
	}
}

void move_conveyor(void)
{
	pair <int, bool> tmp_top = A_top.back();
	pair <int, bool> tmp_bot = A_bot.front();

	A_top.push_front(tmp_bot);
	A_top.pop_back();
	A_bot.push_back(tmp_top);
	A_bot.pop_front();
	A_top[N - 1].second = false;
}

int check_durability(void)
{
	int zero_durability = 0;

	for (int i = 0; i < N; i++)
	{
		if (A_top[i].first == 0)
			zero_durability++;
		if (A_bot[i].first == 0)
			zero_durability++;
	}
	return zero_durability;
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		A_top.push_back(make_pair(tmp, false));
	}
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		A_bot.push_front(make_pair(tmp, false));
	}
	while(1)
	{
		cycle_cnt++;
		move_conveyor();
		move_robot();
		put_robot();
		if (check_durability() >= K)
			break ;
	}
	cout << cycle_cnt;
}
