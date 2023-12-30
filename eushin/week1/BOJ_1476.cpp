#include <iostream>
using namespace std;
int E, S, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> E >> S >> M;

	int res = 1;
	if (E == 15)
		E = 0;
	if (S == 28)
		S = 0;
	if (M == 19)
		M = 0;
	while (1)
	{
		if (res % 15 == E && res % 28 == S && res % 19 == M)
			break ;
		res++;
	}
	cout << res;

}