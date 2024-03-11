#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S, T;

void Input()
{
	cin >> S >> T;
}

void Solution()
{
	while (true)
	{
		if (T[T.size()-1] == 'A')
			T.pop_back();
		else
		{
			T.pop_back();
			reverse(T.begin(), T.end());
		}
		if (T.size() == S.size())
		{
			if (T == S)
				cout << 1;
			else
				cout << 0;
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
