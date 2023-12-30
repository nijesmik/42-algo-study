#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, tmp, chicken_num, res;
vector <pair<int, int>> chicken, house, v;
bool visited[13];

int GetDist()
{
	int total = 0;
	for (int i = 0; i < (int)house.size(); i++)
	{
		int r1 = house[i].first;
		int c1 = house[i].second;
		int min_dist = 2147483647;

		for (int j = 0; j < v.size(); j++)
		{
			int r2 = v[j].first;
			int c2 = v[j].second;
			int dist = abs(r2 - r1) + abs(c2 - c1);
			min_dist = min(min_dist, dist);
		}
		total += min_dist;
	}
	return total;
}

void SelectChicken(int idx, int cnt)
{
	if (cnt == M)
	{
		res = min(res, GetDist());
		return ;
	}
	for (int i = idx; i < chicken_num; i++)
	{
		if (visited[i] == true)
			continue;
		visited[i] = true;
		v.push_back(chicken[i]);
		SelectChicken(i, cnt + 1);
		v.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	res = 2147483647;
	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> tmp;
			if (tmp == 1)
				house.push_back(make_pair(r, c));
			else if (tmp == 2)
				chicken.push_back(make_pair(r, c));
		}
	}
	chicken_num = chicken.size();
	SelectChicken(0, 0);
	cout << res;
}