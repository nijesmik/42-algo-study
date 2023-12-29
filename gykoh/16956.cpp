#include <iostream>
using namespace std;

int R, C;
string field[501];

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> field[i];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) 
		{
			if (field[i][j] == 'S') 
			{
				if ((i > 0 && field[i - 1][j] == 'W') || 
					(i < R - 1 && field[i + 1][j] == 'W') || 
					(j > 0 && field[i][j - 1] == 'W') || 
					(j < C - 1 && field[i][j + 1] == 'W')) 
				{
					cout << 0 << endl;
					return (0);
				}
			} 
			else if (field[i][j] == '.')
				field[i][j] = 'D';
		}
	}
	cout << 1 << endl;
	for (int i = 0; i < R; i++)
		cout << field[i] << endl;
	return (0);
}
