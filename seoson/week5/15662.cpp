#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int T,K,cnt;
vector<string> vec;
int isUsed[1000];

void	check_right(int index)
{
	if (index == T)
		return ;
	if (vec[index - 1][2] == vec[index][6])
		return ;
	isUsed[index] = isUsed[index - 1] * -1;
	check_right(index + 1);
}

void	check_left(int index)
{
	if (index == -1)
		return ;
	if (vec[index][2] == vec[index + 1][6])
		return ;
	isUsed[index] = isUsed[index + 1] * -1;
	check_left(index - 1);
}

void	rotate()
{
	for(int i = 0; i < T; i++)
	{
		string s;
		deque<char> q;
		if (isUsed[i] == -1)
		{
			for(int j = 0; j < 8; j++)
				q.push_back(vec[i][j]);
			q.push_back(q.front());
			q.pop_front();
			while (!q.empty())
			{
				s += q.front();
				q.pop_front();
			}
			vec[i] = s;
		}
		else if (isUsed[i] == 1)
		{
			for(int j = 0; j < 8; j++)
				q.push_back(vec[i][j]);
			q.push_front(q.back());
			q.pop_back();
			while (!q.empty())
			{
				s += q.front();
				q.pop_front();
			}
			vec[i] = s;
		}
	}
}

int main()
{
	string tmp;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> tmp;
		vec.push_back(tmp);
	}
	cin >> K;
	int num,dir;
	for(int i = 0; i < K; i++)
	{
		for(int j = 0; j < T; j++)
			isUsed[j] = 0;
		cin >> num >> dir;
		isUsed[num - 1] = dir;
		check_right(num);
		check_left(num - 2);
		rotate();
	}
	for(int i = 0; i < T; i++)
	{
		if (vec[i][0] == '1')
			cnt++;
	}
	cout << cnt;
	return (0);
}