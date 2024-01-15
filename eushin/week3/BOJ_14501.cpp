#include <iostream>
#include <algorithm>
using namespace std;
int N;
int cost[17];
vector <pair<int, int>> schedule;


void GetCost()
{
	int limit;
	for (int i = N; i > 0; i--)
	{
		limit = i + schedule[i].first - 1;
		if (limit > N)
			cost[i] = cost[i+1];
		else
			cost[i] = max(cost[i+1], cost[limit+1] + schedule[i].second);
	}
}

void Input()
{
	cin >> N;
	schedule.push_back({-1, -1});
	for (int i = 0; i < N; i++)
	{
		int time, pay;
		cin >> time >> pay;
		schedule.push_back({time, pay});
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	GetCost();

	cout << cost[1];
}