#include <iostream>
using namespace std;
int N, M, cnt, sum;
int perm[10001];

// 연속된 부분 수열의 합이 M이 되는 경우
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		 cin >> perm[i];
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = i; j < N; j++) {
			sum += perm[j];
			if (sum > M)
				break;
			else if (sum == M)
			{
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}