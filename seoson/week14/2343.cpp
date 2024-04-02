#include <iostream>

using namespace std;
int N, M;
int mn;
int board[100000];

int binary_search()
{
	int left = mn;
	int right = 1000000000;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int cnt = 0, sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += board[i];
			if (sum > mid)
			{
				i--;
				sum = 0;
				cnt++;
			}
		}
		if (cnt >= M)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
		mn = max(mn, board[i]);
	}
	cout << binary_search();
	return (0);
}