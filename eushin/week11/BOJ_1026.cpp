#include <iostream>
#include <algorithm>
using namespace std;
int N, answer;
int A[50], B[50];

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
}

void Solution()
{
	sort(A, A+N);
	sort(B, B+N, greater<>());
	for (int i = 0; i < N; i++)
		answer += (A[i] * B[i]);
	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
