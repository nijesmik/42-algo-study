#include <iostream>
using namespace std;
int N;
int dp[35];

void Input()
{
	cin >> N;
}

void Solution()
{
	if (N % 2 == 1)
	{
		cout << 0;
		return;
	}
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= N; i += 2)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
			dp[i] += dp[j] * 2;
	}
	cout << dp[N];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}