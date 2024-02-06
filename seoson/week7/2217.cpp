#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int N,max_val;
int main()
{
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for(int i = 1; i <= N; i++)
		max_val = max(max_val, arr[N - i] * i);
	cout << max_val;
	return (0);
}