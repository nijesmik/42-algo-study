#include <iostream>
#include <vector>
using namespace std;

int N, M;
int sum, cnt;
vector<int> A;
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = i; j < N; j++)
		{
			sum += A[j];
			if (sum == M)
			{
				cnt++;
				break;
			}
			else if (sum > M)
				break;
		}
	}
	cout << cnt << endl;
}
