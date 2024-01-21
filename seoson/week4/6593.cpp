#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int ans;
bool flag;
char board[30][30][30];
int visited[30][30][30];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
queue<tuple<int, int, int>> q;
int main()
{
	while (1)
	{
		int L,R,C;
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break ;
		for(int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				for (int k = 0; k < 30; k++){
					visited[i][j][k] = 0;
				}
			}
		}
		flag = false;
		for (int j = L - 1; j >= 0; j--){
			for (int k = 0; k < R; k++){
				for (int l = 0; l < C; l++){
					cin >> board[j][k][l];
					if (board[j][k][l] == 'S')
					{
						q.push({j,k,l});
						visited[j][k][l] = 1;
					}
				}
			}
		}
		while (!q.empty())
		{
			tuple<int,int,int> curr = q.front();
			q.pop();
			for(int dir = 0; dir < 6; dir++)
			{
				int nx = get<2>(curr) + dx[dir];
				int ny = get<1>(curr) + dy[dir];
				int nz = get<0>(curr) + dz[dir];
				if (nx < 0 || ny < 0 || nz < 0 || nx >= C || ny >= R || nz >= L)
					continue ;
				if (board[nz][ny][nx] == 'E' && flag == false)
				{
					flag = true;
					cout << "Escaped in " << visited[get<0>(curr)][get<1>(curr)][get<2>(curr)] << " minute(s)." << "\n";
					break ;
				}
				if (board[nz][ny][nx] == '#' || visited[nz][ny][nx] != 0)
					continue ;
				visited[nz][ny][nx] = visited[get<0>(curr)][get<1>(curr)][get<2>(curr)] + 1;
				q.push({nz,ny,nx});
			}
		}
		if (flag == false)
			cout << "Trapped!" << "\n";
	}
	return (0);
}