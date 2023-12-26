#include <iostream>
using namespace std;

int main()
{
	int e, s, m;
	cin >> e >> s >> m;

	int tmp_e = 1, tmp_s = 1, tmp_m = 1;
	int year = 1;
	while (1)
	{
		if (tmp_e == e && tmp_s == s && tmp_m == m)
			break ;
		if (tmp_e == 15)
			tmp_e = 0;
		if (tmp_s == 28)
			tmp_s = 0;
		if (tmp_m == 19)
			tmp_m = 0;
		tmp_e++;
		tmp_s++;
		tmp_m++;
		year++;
	}
	cout << year;
	return (0);
}
