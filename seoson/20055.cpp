#include <iostream>
#include <deque>

using namespace std;
int N,K;
int ans;
deque<bool>	robot;
deque<int> deq;

void	rotate()
{
	deq.push_front(deq.back());
	deq.pop_back();
	robot.push_front(robot.back());
	robot.pop_back();
	if (robot[N - 1] == true)
		robot[N - 1] = false;
}

void	move_robot()
{
	for (int i = N - 2; i >= 0; i--)
	{
		if (robot[i] == true && robot[i + 1] == false && deq[i + 1] >= 1)
		{
			deq[i+1]--;
			robot[i] = false;
			if (i == N - 2)
				continue ;
			robot[i + 1] = true;
		}
	}
}

void	put_robot()
{
	if (deq[0] >= 1 && robot[0] == false)
	{
		deq[0]--;
		robot[0] = true;
	}
}

int check_finish()
{
	int cnt = 0;
	for (int i = 0; i < deq.size(); i++)
	{
		if (deq[i] == 0)
			cnt++;
	}
	return (cnt);
}

int main()
{
	cin.tie();
	ios::sync_with_stdio(0);
	int input;
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++)
	{
		cin >> input;
		deq.push_back(input);
		robot.push_back(false);
	}
	while (1)
	{
		if (check_finish() >= K)
			break ;
		ans++;
		rotate();
		move_robot();
		put_robot();
	}
	cout << ans;
	return (0);
}