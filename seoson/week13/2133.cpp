#include <iostream>

using namespace std;
int N,cnt;
long long arr[31];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> N;
	arr[2] = 3;
	for(int i = 3; i <= N; i++)
	{
		if (i % 2 == 1)
			continue;
		arr[i] = arr[i - 2] * 3;
		for(int j = i - 4; j >= 1; j -= 2)
			arr[i] += arr[j] * 2;
		arr[i] += 2;
	}
	cout << arr[N];
	return (0);
}