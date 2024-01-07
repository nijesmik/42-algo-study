#include <iostream>

using namespace std;

int	N, M, sum, res;

int	main(void)
{
	cin >> N >> M;

	int	arr[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = i; j < N; j++)
		{
			sum += arr[j];
			if (sum == M)
			{
				res++;
				break;
			}
		}
	}

	cout << res;
	return 0;
}
