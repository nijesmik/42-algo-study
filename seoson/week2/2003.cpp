#include <iostream>
using namespace std;
int arr[10001];
int N,M,cnt;
int main()
{
	long long sum;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = i; j < N; j++)
		{
			sum += arr[j];
			if (sum == M)
				cnt++;
		}
	}
	cout << cnt;
	return (0);
}