#include <iostream>
#include <algorithm>

using namespace std;
int arr[10001];
int N;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	if (next_permutation(arr, arr+N))
	{
		for (int i = 0; i < N; i++)
			cout << arr[i] << " ";
	}
	else
		cout << "-1";
	return (0);
}
