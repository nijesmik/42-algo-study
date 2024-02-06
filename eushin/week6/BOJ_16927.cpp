#include <iostream>
#include <algorithm>
using namespace std;

int N, M, R;
int r, c, k, n, m, val, cnt;
int map[301][301];
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

void rotate(int start, int len)
{
    
    r = R % len;
    for (int i = 0; i < r; i++)
    {
        
        val = map[start][start];
        r = start;
        c = start;
        
        k = 0;
        while(k < 4)
        {
            
            int nr = r + dr[k];
            int nc = c + dc[k];
            
            if (nr == start && nc == start)
                break;
            if (start <= nr && nr < N - start && start <= nc && nc < M - start)
            { 
                map[r][c] = map[nr][nc];
                r = nr;
                c = nc;
            }
            else
                k++;
        }
        map[start + 1][start] = val;
    }
}


int main()
{
    
    cin >> N >> M >> R;
        
    for (int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> map[i][j];  
            
    cnt = min(N,M) / 2; 
    n = N;
    m = M;
    
    for (int i = 0; i < cnt; i++)
    {
        rotate(i, 2*n + 2*m - 4);
        n -= 2;
        m -= 2;
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cout << map[i][j] << " ";
        cout <<"\n";
    }
}