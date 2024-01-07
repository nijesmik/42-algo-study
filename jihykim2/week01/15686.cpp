#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

#define TRUE 1
#define FALSE 0

int		N, M, RES;
int		chicken_cnt, home_cnt;
int		city[50][50];
int		Select[13];
vector	< pair<int, int> > home, chicken, combination;

int		Min(int a, int b);
void	find_combination(int index, int count);
int		get_min_distance(void);

int	main(void)
{
	/* 1. 입력을 받아 치킨집과 집의 좌표를 저장한다 */
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 2)
				chicken.push_back(make_pair(i, j));
			else if (city[i][j] == 1)
				home.push_back(make_pair(i, j));
		}
	}

	/* 2. 조합(nCm)을 구하여 최소 거리를 구한다 */
	RES = 2147483647;
	chicken_cnt = chicken.size();
	home_cnt = home.size();
	find_combination(0, 0);

	cout << RES << endl;

	return (0);
}
void	find_combination(int index, int count)
{
	if (count == M)
	{
		RES = Min(RES, get_min_distance());
		return ;
	}
	for (int i = index; i < chicken_cnt; i++)
	{
		if (Select[i] == TRUE)
			continue;
		Select[i] = TRUE;
		combination.push_back(chicken[i]);
		find_combination(i, count + 1);
		Select[i] = FALSE;
		combination.pop_back();
	}
}

int	get_min_distance(void)
{
	int	chicken_dist = 0;
	int	combination_cnt = combination.size();

	for (int h = 0; h < home_cnt; h++)
	{
		int	minimum = 2147483647;
		for (int c = 0; c < combination_cnt; c++)
		{
			int	distance = abs(home[h].first - combination[c].first) \
						 + abs(home[h].second - combination[c].second);
			minimum = Min(minimum, distance);
		}
		chicken_dist += minimum;
	}
	return (chicken_dist);
}

int	Min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
