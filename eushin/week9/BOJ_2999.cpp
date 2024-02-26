#include <iostream>
#include <cmath>
using namespace std;
string encrypted_msg;

void Input()
{
	cin >> encrypted_msg;
}

void Solution()
{
	int R, C;
	int size = encrypted_msg.length();
	
	for (int i = sqrt(size); i > 0; i--)
	{
		if (size % i == 0)
		{
			R = i;
			C = size / i;
			break;
		}
	}

	char arr[C][R];
	int idx = 0;

	for (int i = 0; i < C; i++)
	{
		for (int j = 0; j < R; j++)
		{
			arr[i][j] = encrypted_msg[idx];
			idx++;
		}
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cout << arr[j][i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
