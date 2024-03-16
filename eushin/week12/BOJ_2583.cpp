#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int M, N, K, cnt;
int board[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[101][101];
vector<int> areas;

void Input()
{
    cin >> M >> N >> K;
    
    for (int i = 0; i < K; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++)
            for (int j = x1; j < x2; j++)
                board[i][j] = 1;
    }
}

void Solution()
{
    for (int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (board[i][j] == 1 || visited[i][j] == 1)
                continue;
                
            queue<pair<int,int>> q;
            
            visited[i][j] = 1;
            q.push({i,j});
            cnt++;
            
            int area = 1;
            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    
                    if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                        continue;
                    if (board[nx][ny] == 1 || visited[nx][ny] == 1)
                        continue;
                    q.push({nx,ny});
                    visited[nx][ny] = 1;
                    area++;
                }
            }
            areas.push_back(area);
        }
    }
    sort(areas.begin(), areas.end());
    cout << cnt << '\n';
    for (int i : areas)
        cout << i << ' ';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    Input();
    Solution();
}