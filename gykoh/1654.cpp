#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int K, N;
vector<int> v;

int	is_valid(int mid, int K)
{
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
		cnt += v[i] / mid;
	if (cnt >= K)
		return (1);
	return (0);
}

int	main()
{
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	long left = 1;
	long right = v.back();
	long res = 0;
	while (left <= right)
	{
		long mid = (left + right) / 2;
		if (is_valid(mid, N))
		{
			res = max(res, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << res << endl;
}
