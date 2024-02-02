#include <iostream>
#include <string>

using namespace std;

long long calc_len(int N)
{
	long long len = 0;
	for (int start = 1, i = 1; start <= N; start *= 10, ++i)
	{
		int end = start * 10 - 1;
		if (end > N)
			end = N;
		len += (long long)(end - start + 1) * i;
	}
	return len;
}

int binary_search(int left, int right, int target)
{
	if (left >= right)
		return (right);
	int mid = (left + right) / 2;
	long long len = calc_len(mid);
	if (len < target)
		return (binary_search(mid + 1, right, target));
	else
		return (binary_search(left, mid, target));
}

int main()
{
	int N, K;
	cin >> N >> K;
	if (calc_len(N) < K)
	{
		cout << -1;
		return (0);
	}
	int num = binary_search(1, N, K);
	int num_len = calc_len(num);
	string s_num = to_string(num);
	cout << s_num[(s_num.size() - 1 - (num_len - K))];
	return (0);
}
