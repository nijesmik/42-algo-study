#include <iostream>

using namespace std;
int N,M,x,y,K;
int arr[20][20];
int dice[6];
//00 00 00
//01 23 45
//상뒤 좌우 앞하
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

void	dice_move(int command)
{
	if (dx[command] == 1) // 동
	{
		int temp = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[0];
		dice[0] = temp;
	}
	else  if(dx[command] == -1) // 서
	{
		int temp = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = dice[0];
		dice[0] = temp;
	}
	else if (dy[command] == 1) // 남
	{
		int temp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[0];
		dice[0] = temp;
	}
	else if (dy[command] == -1) // 북
	{
		int temp = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[0];
		dice[0] = temp;
	}
}

int main()
{
	cin >> N >> M >> y >> x >> K;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	int command;
	for(int i = 0; i < K; i++)
	{
		cin >> command;
		int dir = command - 1;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue ;
		dice_move(dir);
		if (arr[ny][nx] == 0)
			arr[ny][nx] = dice[5];
		else
		{
			dice[5] = arr[ny][nx];
			arr[ny][nx] = 0;
		}
		x = nx;
		y = ny;
		cout << dice[0] << "\n";
	}
	return (0);
}
