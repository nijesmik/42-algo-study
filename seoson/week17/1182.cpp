#include <iostream>
#include <vector>
using namespace std;
int N,S,cnt;
vector<int> vec;
void check(vector<int>& temp)
{
	long long sum = 0;
	bool flag = false;
	for(int i = 0; i < temp.size(); i++)
	{
		sum += temp[i];
		flag = true;
	}
	if (sum == S && flag)
		cnt++;
}

void solve(int depth, vector<int>& temp)
{
	check(temp);
	if (depth == vec.size())
		return ;
	for(int i = depth + 1; i < vec.size(); i++)
	{
		temp.push_back(vec[i]);
		solve(i, temp);
		temp.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> N >> S;
	for(int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}
	vector<int> temp;
	solve(-1, temp);
	cout << cnt;
	return (0);
}