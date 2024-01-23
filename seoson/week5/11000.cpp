#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
vector<pair<int, int>> vec;
int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int S,T;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> S >> T;
		vec.push_back({S,T});
	}
	sort(vec.begin(),vec.end());
	q.push(vec[0].second);
	for(int i = 1; i < N; i++)
	{
		if (q.top() <= vec[i].first)
			q.pop();
		q.push(vec[i].second);
	}
	cout << q.size();
	return (0);
}