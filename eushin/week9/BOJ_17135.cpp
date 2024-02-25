#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const pii NO_TARGET = {-1, -1};
int N, M, D;
int board[15][15];
bool isDead[15][15];

void Input()
{
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
}

pii CalTarget(int r, int c)
{
    for (int d = 1; d <= D; d++)
    {
        for (int dc = -(d-1); dc <= (d-1); dc++)
        {
            int dr = -(d - abs(dc));
            int er = r + dr;
            int ec = c + dc;

            if (er < 0 || er >= N || ec < 0 || ec >= M)
                continue;
            if (board[er][ec] == 1 && isDead[er][ec] == 0)
                return {er, ec};
        }
    }
    return NO_TARGET;
}

int Simulate(int archer1, int archer2, int archer3)
{
    int killCnt = 0;
    vector<int> archers = {archer1, archer2, archer3};
    
    memset(isDead, 0, sizeof(isDead));
    for (int i = N; i > 0; i--)
    {
        vector<pii> targets;
        
        for (auto archer: archers)
            targets.push_back(CalTarget(i, archer));
        for (auto target: targets)
        {
            if (target == NO_TARGET)
                continue;
            
            int r = target.first;
            int c = target.second;
            
            if (isDead[r][c] == 0)
                killCnt++;
            isDead[r][c] = true;
        }
    }
    return killCnt;
}

void Solution()
{
    int maxKill = 0;
    
    for (int i = 0; i < M-2; i++)
        for (int j = i+1; j < M-1; j++)
            for (int k = j+1; k < M; k++)
                maxKill = max(maxKill, Simulate(i, j, k));
    cout << maxKill;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    Input();
    Solution();
}