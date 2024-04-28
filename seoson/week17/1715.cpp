#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
long long sum;
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		pq.push(input);
	}
	if (N == 1)
	{
		cout << "0";
		return (0);
	}
	while(!pq.empty())
	{
		int temp = pq.top();
		pq.pop();
		if (pq.size() == 0)
			break ;
		int temp2 = pq.top();
		pq.pop();
		sum += temp + temp2;
		pq.push(temp + temp2);
	}
	cout << sum;
	return (0);
}