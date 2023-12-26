#include <iostream>

int ans,E_TEMP,S_TEMP,M_TEMP;
using namespace std;
int main()
{
	int E,S,M;
	cin >> E >> S >> M;
	while (1)
	{
		E_TEMP++, S_TEMP++, M_TEMP++, ans++;
		if (E_TEMP > 15)
			E_TEMP = 1;
		if (S_TEMP > 28)
			S_TEMP = 1;
		if (M_TEMP > 19)
			M_TEMP = 1;
		if (E_TEMP == E && S_TEMP == S && M_TEMP == M)
			break;
	}
	cout << ans;
	return (0);
}
