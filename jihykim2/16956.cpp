#include <iostream>

using namespace std;

int	main(void)
{
	string	farm[501];
	int		row, col;
	int		w, s, a, d;

	cin >> row >> col;
	for (int i = 0; i < row; i++)
		cin >> farm[i];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; i < col; j++)
		{
			if (farm[i][j] == 'W')
			{
				w = i - 1;
				s = i + 1;
				a = j - 1;
				d = j + 1;
				if (w >= 0 && farm[w][j] == 'S' || s < row && farm[s][j] == 'S' \
					|| a >= 0 && farm[i][a] == 'S' || d < col && farm[i][d] == 'S')
				{
					cout << 0;
					return (0);
				}
			}
			else if (farm[i][j] == '.')
				farm[i][j] = 'D';
		}
	}

	cout << 1;
	for (int i = 0; i < row; i++)
		cout << farm[i] << endl;

	return (0);
}
