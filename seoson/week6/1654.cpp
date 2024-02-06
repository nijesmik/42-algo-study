#include <iostream>
#include <algorithm>
using namespace std;
int N,K,max_val;
unsigned int ans;
int arr[1000000];
int main()
{
	cin >> K >> N;
	for(int i = 0; i < K; i++)
	{
		cin >> arr[i];
		max_val = max(max_val, arr[i]);
	}
	unsigned int left,right,mid;
	left = 1, right = max_val;
	while (left<=right)
	{
		unsigned int cnt = 0;
		mid = (left + right) / 2;
		for(int i = 0; i < K; i++)
			cnt += arr[i] / mid;
		if (cnt >= N)
		{
			left = mid + 1;
			ans = max(ans, mid);
		}
		else
			right = mid - 1;
	}
	cout << ans;
	return (0);
}