#include <iostream>
using namespace std;

int n;
long long fibonacci[93];

long long Fibonacci(int n)
{
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	
	for (int i = 2; i <= n; i++)
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
	return fibonacci[n];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cout << Fibonacci(n);
}
