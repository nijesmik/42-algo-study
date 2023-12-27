#include <iostream>

using namespace std;

int	main(void)
{
	int	E, S, M;
	int	year = 1;

	cin >> E >> S >> M;
	E %= 15;
	S %= 28;
	M %= 19;
	while (true)
	{
		if (year % 15 == E && year % 28 == S && year % 19 == M)
			break;
		year++;
	}
	cout << year;

	return (0);
}
