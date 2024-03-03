#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int arr[1000];
vector<int> sum;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
			sum.push_back(arr[i] + arr[j]);
	}
	sort(sum.begin(), sum.end());
	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (binary_search(sum.begin(), sum.end(), arr[i] - arr[j]))
			{
				cout << arr[i];
				return (0);
			}
		}
	}
	return (0);
}