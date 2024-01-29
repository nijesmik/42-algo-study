#include <iostream>
#include <cmath>
using namespace std;

int N;
int sum;
int main()
{
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int left = 0, right = N - 1;
	int min = 200000001;
	while (left < right)
	{
		sum = arr[left] + arr[right];
		if (abs(sum) < abs(min))
			min = sum;
		if (sum > 0)
		{
			right--;
		}
		else if (sum < 0)
		{
			left++;
		}
		else
			break;
	}
	cout << min << endl;
}
