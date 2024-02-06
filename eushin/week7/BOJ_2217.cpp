#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> ropes, weight;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		ropes.push_back(tmp);
	}
}

void Solution()
{
	sort(ropes.begin(), ropes.end());
	for (int i = 0; i < N; i++)
	{
		int w = ropes[i] * (N - i);
		weight.push_back(w);
	}
	sort(weight.begin(), weight.end(), greater<>());
	cout << weight[0];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}