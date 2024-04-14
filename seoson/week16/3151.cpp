#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
long long int cnt;
vector<int> vec;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < N - 1; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			long long sum = vec[i] + vec[j];
			int temp1 = lower_bound(vec.begin() + j + 1, vec.end(), -sum) - vec.begin();
			int temp2 = upper_bound(vec.begin() + j + 1, vec.end(), -sum) - vec.begin();
			cnt += temp2 - temp1;
		}
	}
	cout << cnt;
	return (0);
}