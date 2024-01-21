#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int arr[100000];
int save[100000];
int	ans[100000];

void	binary_search(int temp, int index)
{
	int start = 0;
	int end = N - 1;
	int mid = end / 2;
	while (start<=end)
	{
		if (arr[mid] == temp)
		{
			ans[index] = 1;
			break ;
		}
		else if (temp > arr[mid])
		{
			start = mid + 1;
			mid = (start + end) / 2;
		}
		else
		{
			end = mid - 1;
			mid = (start + end) / 2;
		}
	}
}

int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> save[i];
	sort(arr,arr+N); //nlogn
	for (int i = 0; i < M; i++)
		binary_search(save[i], i);
	for (int i = 0 ; i < M; i++)
		cout << ans[i] << "\n";
	return (0);
}
