#include <iostream>
using namespace std;

int N;
long long X;
long long total_len;
long long half;

long long get_total_len(int n)
{
	if (n == 0)
		return (1);
	return (get_total_len(n - 1) * 2 + 3);
}

long long get_patty_cnt(int N, long long X)
{
	if (N == 0)
	{
		if (X >= 1)
			return (1);
		else
			return (0);
	}
	total_len = get_total_len(N);
	half = total_len / 2;
	if (X == 1)
		return (0);
	if (X <= half)
		return (get_patty_cnt(N - 1, X - 1));
	else if (X == half + 1)
		return (get_total_len(N - 1) / 2 + 1);
	else
		return (get_total_len(N - 1) / 2 + 1 + get_patty_cnt(N - 1, X - half + 1));
}

int main()
{
	cin >> N >> X;
	cout << get_patty_cnt(N, X) << "\n";
	return (0);
}
