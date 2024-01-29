#include <iostream>

using namespace std;
long long N,cnt,X;
long long total[51];
long long P[51];

long long	recursive(long long N, long long X)
{
	if (N == 0)
	{
		if (X == 1)
			return (1);
		else
			return (0);
	}
	if (X == 1)
		return (0);
	if (X <= total[N - 1] + 1)
		return (recursive(N - 1, X - 1));
	else if (X == 1 + total[N - 1] + 1)
		return (P[N - 1] + 1);
	else if (X <= 1 + total[N - 1] + 1 + total[N - 1])
		return (1 + P[N - 1] + recursive(N - 1, X - 1 - total[N - 1] - 1));
	else
		return (2 * P[N - 1] + 1);
}

int main()
{
	cin >> N >> X;
	total[0] = 1;
	P[0] = 1;
	for(long long i = 1; i <= N; i++)
	{
		total[i] = 1 + total[i - 1] + 1 + total[i - 1] + 1;
		P[i] = P[i - 1] + 1 + P[i - 1];
	}
	cout << recursive(N,X);
	return (0);
}