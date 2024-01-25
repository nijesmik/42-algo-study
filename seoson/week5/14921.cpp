#include <iostream>
#include <algorithm>
using namespace std;
int N,ans;
int arr[100001];
int main()
{
	ans = 2147483647;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	int start = 0;
	int ed = N - 1;
	int sum;
	while (start < ed)
	{
		sum = arr[start] + arr[ed];
		if (abs(sum) < abs(ans))
			ans = sum;
		if (sum == 0)
			break ;
		else if (sum < 0)
			start++;
		else
			ed--;
	}
	cout << ans;
	return (0);
}
