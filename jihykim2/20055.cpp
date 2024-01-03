#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int	N, K, cnt;
deque<pair<int, bool>>	dq;

void	rotate_dq(void);
void	move_robot(void);
void	put_robot(void);

int	main(void)
{
	cin >> N >> K;

	int	dur;
	for (int i = 0; i < 2 * N; i++)
	{
		cin >> dur;
		dq.push_back(make_pair(dur, false));
	}

	while (K > 0)
	{
		cnt++;
		rotate_dq();
		move_robot();
		put_robot();
	}

	cout << cnt;

	return (0);
}

void	rotate_dq(void)
{
	int		temp_dur = dq.back().first;
	bool	temp_robot = dq.back().second;
	dq.pop_back();
	dq.push_front(make_pair(temp_dur, temp_robot));
	dq[N - 1].second = false;			// N번째의 로봇은 무조건 내린다(= false)
}

void	move_robot(void)
{
	for (int i = N - 2; i >= 0; i--)
	{
		if (dq[i].second == true && dq[i + 1].second == false && dq[i + 1].first > 0)
		{
			dq[i].second = false;
			dq[i + 1].second = true;
			if (--(dq[i + 1].first) == 0)
				K--;
		}
	}
	dq[N - 1].second = false;			// N번째의 로봇은 무조건 내린다(= false)
}

void	put_robot(void)
{
	if (dq.front().first == 0)
		return ;
	dq.front().second = true;
	if (--dq.front().first == 0)
		K--;
}

/*
4 5
10	1	10	6
2	8	4	3

===============
[1-1]
2	10	1	10
8	4	3	6
[1-2]
[1-3]
1r	10	1	10
8	4	3	6
===============
[2-1]
8	1r	10	1
4	3	6	10
[2-2]
8	1	9r	1
4	3	6	10
[2-3]
7r	1	9r	1
4	3	6	10
===============


*/
