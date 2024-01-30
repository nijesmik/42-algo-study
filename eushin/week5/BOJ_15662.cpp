#include <iostream>
#include <vector>
using namespace std;
int T, K;
int cnt;
vector <pair<string, pair<int,int>>> wheels; // n/s string, cur, prev
vector <pair<int, int>> rotate_info;

void Input()
{
	cin >> T;
	wheels.push_back({"000", {0, 0}});
	for (int i = 0; i < T; i++)
	{
		string tmp;
		cin >> tmp;
		wheels.push_back({tmp, {0, 0}});
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int num, dir;
		cin >> num >> dir;
		rotate_info.push_back({num, dir});
	}
}

void rotate_front(int std_num, int std_dir)
{
	int cur_dir = std_dir;
	for (int i = std_num; i >= 2; i--)
	{
		if (i % 2 == 0)
		{
			int idx_o = (2 + wheels[i-1].second.second) % 8; // idx when odd
			int idx_e = (6 + wheels[i].second.second) % 8; // idx when even
			if (wheels[i].first[idx_e] != wheels[i-1].first[idx_o])
			{
				if (cur_dir == 1)
				{
					wheels[i-1].second.first += 1;
					cur_dir = -1;
				}
				else
				{
					wheels[i-1].second.first += 7;
					cur_dir = 1;
				}
				continue ;
			}
			return ;
		}
		else
		{
			int idx_o = (6 + wheels[i].second.second) % 8; // idx when odd
			int idx_e = (2 + wheels[i-1].second.second) % 8; // idx when even
			if (wheels[i].first[idx_o] != wheels[i-1].first[idx_e])
			{
				if (cur_dir == 1)
				{
					wheels[i-1].second.first += 1;
					cur_dir = -1;
				}
				else
				{
					wheels[i-1].second.first += 7;
					cur_dir = 1;
				}
				continue ;
			}
			return ;
		}
	}
}

void rotate_back(int std_num, int std_dir)
{
	int cur_dir = std_dir;
	for (int i = std_num; i < T; i++)
	{
		if (i % 2 == 0)
		{
			int idx_o = (6 + wheels[i+1].second.second) % 8; // idx when odd
			int idx_e = (2 + wheels[i].second.second) % 8; // idx when even
			if (wheels[i].first[idx_e] != wheels[i+1].first[idx_o])
			{
				if (cur_dir == 1)
				{
					wheels[i+1].second.first += 1;
					cur_dir = -1;
				}
				else
				{
					wheels[i+1].second.first += 7;
					cur_dir = 1;
				}
				continue ;
			}
			return ;
		}
		else
		{
			int idx_o = (2 + wheels[i].second.second) % 8; // idx when odd
			int idx_e = (6 + wheels[i+1].second.second) % 8; // idx when even
			if (wheels[i].first[idx_o] != wheels[i+1].first[idx_e])
			{
				if (cur_dir == 1)
				{
					wheels[i+1].second.first += 1;
					cur_dir = -1;
				}
				else
				{
					wheels[i+1].second.first += 7;
					cur_dir = 1;
				}
				continue ;
			}
			return ;
		}
	}

}

void Solution()
{
	for (int i = 0; i < K; i++)
	{
		rotate_front(rotate_info[i].first, rotate_info[i].second);
		rotate_back(rotate_info[i].first, rotate_info[i].second);
		if (rotate_info[i].second == 1)
			wheels[rotate_info[i].first].second.first += 7;
		else
			wheels[rotate_info[i].first].second.first += 1;
		for (int j = 1; j <= T; j++)
			wheels[j].second.second = wheels[j].second.first;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();

	for (int i = 1; i <= T; i++)
	{
		int idx = wheels[i].second.first % 8;
		if (wheels[i].first[idx] == '1')
			cnt++;
	}
	cout << cnt;
}