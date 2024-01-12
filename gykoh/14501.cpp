#include <iostream>
#include <cmath>
using namespace std;

int T[16] = {
	0,
};
int P[16] = {
	0,
};
int dp[16] = {
	0,
};

int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];
	int next;
	for (int i = N; i > 0; i--)
	{
		next = i + T[i];
		if (next > N + 1)
			dp[i] = dp[i + 1];
		else
			dp[i] = max(dp[next] + P[i], dp[i + 1]);
	}
	cout << dp[1] << endl;
}
