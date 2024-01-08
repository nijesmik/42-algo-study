#include <iostream>

using namespace std;
int arr[10001];
int N,M,cnt,start_idx,end_idx,sum;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sum = arr[0];
	while (end_idx < N)
	{
		if (sum < M)
		{
			if (++end_idx < N)
				sum += arr[end_idx];
		}
		else if (sum > M)
			sum -= arr[start_idx++];
		else
		{
			sum -= arr[start_idx++];
			if (++end_idx < N)
				sum += arr[end_idx];
			cnt++;
		}
	}
	cout << cnt;
	return (0);
}