#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int r, c, k, cnt;
int height = 3, width = 3;
int arr[101][101];
void R_calc()
{
	int arr_cnt[101];
	int temp = 0;
	for (int i = 1; i <= height; i++)
	{
		vector<pair<int, int>> vec;
		memset(arr_cnt, 0, sizeof(arr_cnt));
		for (int j = 1; j <= width; j++)
			arr_cnt[arr[i][j]]++;
		for (int j = 1; j < 101; j++)
		{
			if (arr_cnt[j] != 0)
				vec.push_back({arr_cnt[j], j});
		}
		sort(vec.begin(), vec.end());
		for (int j = 1; j <= width; j++)
			arr[i][j] = 0;
		int idx = 1;
		for (int j = 0; j < vec.size(); j++)
		{
			arr[i][idx++] = vec[j].second;
			arr[i][idx++] = vec[j].first;
		}
		temp = max(temp, idx);
	}
	width = temp - 1;
}

void C_calc()
{
	int arr_cnt[101];
	int temp = 0;
	for (int i = 1; i <= width; i++)
	{
		vector<pair<int, int>> vec;
		memset(arr_cnt, 0, sizeof(arr_cnt));
		for (int j = 1; j <= height; j++)
			arr_cnt[arr[j][i]]++;
		for (int j = 1; j < 101; j++)
		{
			if (arr_cnt[j] != 0)
				vec.push_back({arr_cnt[j], j});
		}
		sort(vec.begin(), vec.end());
		for (int j = 1; j <= height; j++)
			arr[j][i] = 0;
		int idx = 1;
		for (int j = 0; j < vec.size(); j++)
		{
			arr[idx++][i] = vec[j].second;
			arr[idx++][i] = vec[j].first;
		}
		temp = max(temp, idx);
	}
	height = temp - 1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	}
	while (1)
	{
		if (arr[r][c] == k)
		{
			cout << cnt;
			return (0);
		}
		if (cnt == 100)
		{
			cout << "-1";
			return (0);
		}
		if (height >= width)
			R_calc();
		else
			C_calc();
		cnt++;
	}
	return (0);
}