#include <iostream>
using namespace std;
int N, ans;
int T[16];
int P[16];
int sum[17];
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i];
		cin >> P[i];
	}
	for (int i = 1; i <= N; i++)
	{
		sum[i] = max(sum[i], sum[i - 1]);
		if (i + T[i] <= N + 1)
			sum[i + T[i]] = max(sum[i + T[i]], sum[i] + P[i]);
	}
	for (int i = 1; i <= N + 1; i++)
		ans = max(ans, sum[i]);
	cout << ans;
	return (0);
}