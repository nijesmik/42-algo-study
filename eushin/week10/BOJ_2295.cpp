#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, answer;
vector<int> U, sumValues;
int combination[3];

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		U.push_back(tmp);
	}
	sort(U.begin(), U.end());
}

void Solution()
{
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			sumValues.push_back(U[i] + U[j]);
	sort(sumValues.begin(), sumValues.end());
	
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (binary_search(sumValues.begin(), sumValues.end(), U[j] - U[i]))
				answer = max(answer, U[j]);
		}
	}
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}

