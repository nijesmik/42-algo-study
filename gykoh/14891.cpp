#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string wheel[4];

void rot_wheel(string &wheel, int direction) 
{
	if (direction == 1) 
	{
		char last = wheel[7];
		for (int i = 7; i > 0; i--)
			wheel[i] = wheel[i - 1];
		wheel[0] = last;
	}
	else if (direction == -1) 
	{
		char first = wheel[0];
		for (int i = 0; i < 7; i++)
			wheel[i] = wheel[i + 1];
		wheel[7] = first;
	}
}

int main() 
{
	for (int i = 0; i < 4; i++)
		cin >> wheel[i];

	int K; 
	cin >> K;
	for (int i = 0; i < K; i++) 
	{
		int rotation[4] = {0};
		int num, direction; 
		cin >> num >> direction;
		num--;
		rotation[num] = direction;
		for (int w = num - 1; w >= 0; w--) 
		{
			if (wheel[w + 1][6] != wheel[w][2])
				rotation[w] = -rotation[w + 1];
			else
				break;
		}

		for (int w = num + 1; w < 4; w++)
		{
			if (wheel[w - 1][2] != wheel[w][6])
				rotation[w] = -rotation[w - 1];
			else 
				break;
		}
		
		for (int j = 0; j < 4; j++)
			rot_wheel(wheel[j], rotation[j]);
	}

	int ans = 0;
	if (wheel[0][0] == '1') ans += 1;
	if (wheel[1][0] == '1') ans += 2;
	if (wheel[2][0] == '1') ans += 4;
	if (wheel[3][0] == '1') ans += 8;
	cout << ans;
}
