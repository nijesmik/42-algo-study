#include <iostream>

using namespace std;
int R, C;
char board[100][100];
int main()
{
	string s;
	cin >> s;
	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = s.length(); j >= 1; j--)
		{
			if (i * j == s.length())
			{
				if (i <= j)
				{
					R = i;
					C = j;
				}
			}
		}
	}
	int k = 0;
	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
			board[j][i] = s[k++];
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << board[i][j];
	}
	return (0);
}