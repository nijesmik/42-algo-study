#include <iostream>
#include <vector>
using namespace std;
int N, ans;
vector<int> vec;
int arr[1000];

int check_ans()
{
	int ret = 0;
	for (int i = 0; i < 3; i++)
		ret += arr[vec[i]];
	for (int i = 0; i < N; i++)
	{
		if (ret == arr[i])
			return (ret);
	}
	return (0);
}

void dfs(int depth)
{
	if (depth == 3)
	{
		ans = max(ans, check_ans());
		return;
	}
	for (int i = depth; i < N; i++)
	{
		vec.push_back(i);
		dfs(depth + 1);
		vec.pop_back();
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	dfs(0);
	cout << ans;
	return (0);
}