#include<iostream>
#include<string>
using namespace std;
int N, K;
int first, last, mid, pos;
string str;

int get_length(int n)
{
	int length = 0;
	for (int first = 1, tmp = 1; first <= n; first *= 10, tmp++)
	{
		last = first * 10 - 1;
		if (last > n)
			last = n;
		length += ((last - first) + 1) * tmp;
	}
	return length;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	if (get_length(N) < K)
	{
		cout << -1 << '\n';
		return 0;
	}

	first = 1;
	last = N;
	while (first <= last)
	{
		mid = (first + last) / 2;
		int len = get_length(mid);
		if (len < K)
			first = mid + 1;
		else
		{
			pos = mid;
			last = mid - 1;
		}
	}
	int length = get_length(pos);
	str = to_string(pos);
	cout << str[str.size() - 1 - (length - K)] << ' ';
}