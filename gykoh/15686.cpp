#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int total_min_distance = 2147483647;
vector<int> home_r, home_c;
vector<int> chicken_r, chicken_c;
vector<bool> visited;

int calc_distance(int r1, int c1, int r2, int c2) 
{
	return (abs(r1 - r2) + abs(c1 - c2));
}

void choose_min_distance() 
{
	int total_distance = 0;
	for (int i = 0; i < home_r.size(); i++) 
	{
		int min_distance = 2147483647;
		for (int j = 0; j < chicken_r.size(); j++) 
		{
			if (visited[j])
			{
				int distance = calc_distance(home_r[i], home_c[i], chicken_r[j], chicken_c[j]);
				if (distance < min_distance)
					min_distance = distance;
			}
		}
		total_distance += min_distance;
	}
	if (total_distance < total_min_distance)
		total_min_distance = total_distance;
}

void choose_chicken(int idx, int cnt) 
{
	if (cnt == M)
		choose_min_distance();
	for (int i = idx; i < chicken_r.size(); i++) 
	{
		if (!visited[i]) 
		{
			visited[i] = true;
			choose_chicken(i, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() 
{
	cin >> N >> M;
	int map;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			cin >> map;
			if (map == 1) 
			{
				home_r.push_back(i);
				home_c.push_back(j);
			}
			else if (map == 2) 
			{
				chicken_r.push_back(i);
				chicken_c.push_back(j);
				visited.push_back(false);
			}
		}
	}
	choose_chicken(0, 0);
	cout << total_min_distance;
	return (0);
}
