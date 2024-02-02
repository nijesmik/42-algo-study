#include <iostream>

using namespace std;
long long N,k;
int main()
{
	cin >> N >> k;
	long long digit = 1; //자리수
	long long digit_sum = 0;
	long long nine = 9;
	long long res;
	while (k > digit * nine)
	{
		k -= digit * nine;
		digit_sum += nine;
		digit++;
		nine *= 10;
	}
	cout << digit_sum << "\n";
	res = (digit_sum + 1) + (k - 1) / digit;
	cout << res << "\n";
	if (res > N)
		cout << "-1";
	else
	{
		string str_result = to_string(res);
		cout << str_result[(k - 1) % digit];
	}
	return (0);
}