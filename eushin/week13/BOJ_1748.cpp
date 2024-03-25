#include<iostream>
using namespace std;
int N, cnt;

void Input()
{
	cin >> N;
}

void Solution()
{
	for (int i = 1; i <= N; i *= 10)
		cnt += N - i + 1;

	cout << cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}