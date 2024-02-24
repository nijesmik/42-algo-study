#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
int c, r;   // c; 가로, r; 세로
string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002];  // 지훈이의 이동시간
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for(int i = 0; i < r; i++)
        cin >> board[i];
    queue<pair<int,int> > Q1;
    queue<pair<int,int> > Q2;
    for(int i = 0; i < r; i++){
        fill(dist1[i], dist1[i] + c, -1);
        fill(dist2[i], dist2[i] + c, -1);
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] == 'F')
            {
                Q1.push({i, j});
                dist1[i][j] = 0;
            }
            if(board[i][j] == 'J')
            {
                Q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }
    while(!Q1.empty())   // dist에 불이 번지는 시간 입력
    {
        pair<int,int> cur = Q1.front();
        Q1.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if(dist1[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }
    while(!Q2.empty())  // 지훈이 탈출 BFS
    {
        pair<int,int> cur = Q2.front();
        Q2.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c)  // 범위를 벗어난 것은 탈출에 성공했다는 의미.
            {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if(dist2[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)   // dist1 != -1은 불이 안번진 곳, 불의 전파시간 비교
                continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}