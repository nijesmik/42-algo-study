#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, cnt;
vector<pair<int, int>> vec;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vec.push_back({a * 100 + b, c * 100 + d});
	}
	sort(vec.begin(), vec.end());
	int end = 301;
	int idx = 0;
	while (end < 1201)
	{
		int temp = 0;
		while (idx < N && vec[idx].first <= end)
		{
			temp = max(temp, vec[idx].second);
			idx++;
		}
		if (temp == 0)
		{
			cnt = 0;
			break;
		}
		end = temp;
		cnt++;
	}
	cout << cnt;
	return (0);
}