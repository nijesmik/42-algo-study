#include <iostream>
using namespace std;

char    board[50][50];
int     N, Max = 1, now;
int     dr[4] = {-1, 1, 0, 0};      // orders: UP, DOWN, RIGHT, LEFT
int     dc[4] = {0, 0, 1, -1};

static int  _count_at_dir(int r, int c, int dir, char n);
static void _update_n_check_continue(int r, int c, int dir);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            cin >> board[r][c];

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            for (int d = 0; d < 4; d++) {
                now = _count_at_dir(r, c, d, board[r][c]);
                if (now >= Max)
                {
                    // cout << "now: " << now << "(" << r << ", " << c << ")" << endl;
                    _update_n_check_continue(r, c, d);      // Max 값 갱신 후 추가 연속 확인해서 Max 값 변경
                }
            }
            // cout << "Max: " << Max << endl;
        }
    }
    cout << Max;
    return 0;
}

static int _count_at_dir(int r, int c, int dir, char n) {
    int nr = r + dr[dir], nc = c + dc[dir];
    int cnt = 1;
    while (nr >= 0 && nr < N && nc >= 0 && nc < N) {
        if (board[nr][nc] != n)
            break;
        cnt++;
        nr += dr[dir];
        nc += dc[dir];
    }
    return cnt;
}

static void _update_n_check_continue(int r, int c, int dir) {
    Max = now;      // 먼저 갱신

    char n = board[n][c];
    int nr = r + dr[dir] * now, nc = c + dc[dir] * now;
    if (nr < 0 || nr >= N || nc < 0 || nc >= N)
        return;
    int now_max = 0;
    for (int i = 0; i < 4; i++) {
        if (i == 0 && dir == 1 || i == 1 && dir == 0 || i == 2 && dir == 3 || i == 3 && dir == 2) continue;
        int cr = nr + dr[i], cc = nc + dc[i];
        if (cr >= 0 && cr < N && cc >= 0 && cc < N && board[cr][cc] == n) {
            int val = _count_at_dir(nr, nc, dir, n);
            // cout << "val: " << val << ", i: " << i << endl;
            if (val > now_max)
                now_max = val;
        }
    }
    if (now_max > 0)
        Max += now_max;
}