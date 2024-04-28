#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int N, cnt;
int arr[4000001];
vector<int> vec;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	if (N == 1)
	{
		cout << "0";
		return (0);
	}
	for (int i = 2; i <= N; i++)
		arr[i] = i;
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i * i; j <= N; j += i)
			arr[j] = 0;
	}
	for (int i = 2; i <= N; i++)
	{
		if (arr[i])
			vec.push_back(i);
	}
	int start = 0, end = 0, sum = 0;
	while (end <= vec.size())
	{
		if (sum < N)
		{
			sum += vec[end];
			end++;
		}
		else
		{
			sum -= vec[start];
			start++;
		}
		if (sum == N)
			cnt++;
	}
	cout << cnt;
	return (0);
}