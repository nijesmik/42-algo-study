#include <iostream>

using namespace std;
int n;
long long arr[91];
int main()
{
	arr[1] = 1;
	for(int i = 2; i <= 90; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	cin >> n;
	cout << arr[n];
	return (0);
}