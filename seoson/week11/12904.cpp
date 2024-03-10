#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
string S,T;
bool ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> S >> T;
	while (1)
	{
		if (T[T.size() - 1] == 'A')
			T.pop_back();
		else
		{
			T.pop_back();
			reverse(T.begin(), T.end());
		}
		if (T.size() == S.size())
		{
			if (strcmp(T.c_str(),S.c_str()) == 0)
				ans = true;
			break ;
		}
	}
	if (ans)
		cout << "1";
	else
		cout << "0";
	return (0);
}