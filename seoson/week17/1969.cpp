#include <iostream>
#include <cstring>
using namespace std;
int N, M, cnt;
string str[1001];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		str[i] = input;
	}
	string s = "";
	for (int i = 0; i < M; i++)
	{
		int board[26];
		memset(board, 0, sizeof(board));
		for(int j = 0; j < N; j++)
			board[str[j][i] - 'A']++;
		char c = str[0][i];
		int temp = 0;
		for(int j = 0; j < 26; j++)
		{
			if (temp < board[j])
			{
				temp = board[j];
				c = j + 'A';
			}
		}
		s += c;
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if (s[j] != str[i][j])
				cnt++;
		}
	}
	cout << s << "\n";
	cout << cnt;
	return (0);
}