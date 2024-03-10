#include <iostream>
#include <vector>
using namespace std;
int N, x, y, d, g, cnt;
int map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<int> direction_info;

void MakeDragonCurve()
{
	int size = direction_info.size();
	
	for (int i = size - 1; i >= 0; i--)
	{
		int tmp = (direction_info[i] + 1) % 4;
		
		x += dx[tmp];
		y += dy[tmp];
		map[x][y] = 1;
		direction_info.push_back(tmp);
	}
}

void Count_Square()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
			if (map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])
				cnt++;
	}
}

void Solution()
{
	while (N--)
	{
		direction_info.clear();
		
		cin >> x >> y >> d >> g;

		map[x][y] = 1;
		x += dx[d];
		y += dy[d];
		map[x][y] = 1;
		direction_info.push_back(d);

		while (g--)
			MakeDragonCurve();

	}

	Count_Square();
	cout << cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	Solution();
}
