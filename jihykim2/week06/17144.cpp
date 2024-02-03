#include <iostream>
#include <queue>
using namespace std;

int room[50][50], temp[50][50];
int R, C, T, pure_1, pure_2, cnt;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
queue<pair<int, int>> dust;

static void _init_data(void);
static void _where_is_dust(void);
static void _dust_diffusion(void);
static void _air_purifier(void);
static void _syncronized(void);
static void _cal_amount_of_dust(void);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    _init_data();

    while (T--) {
        _where_is_dust();
        _dust_diffusion();
        _air_purifier();
        _syncronized();
    }
    _cal_amount_of_dust();
    cout << cnt;
    return 0;
}

static void _init_data(void) {
    cin >> R >> C >> T;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> room[r][c];
            temp[r][c] = room[r][c];
            if (room[r][c] == -1)
                pure_2 = r;
        }
    }
    pure_1 = pure_2 - 1;
}

static void _where_is_dust(void) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (room[r][c] > 0)
                dust.push(make_pair(r, c));
        }
    }
}

static void _dust_diffusion(void) {
    while (dust.empty() == false) {
        int r = dust.front().first;
        int c = dust.front().second;
        int share = temp[r][c] / 5;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (temp[nr][nc] < 0) continue;
            room[nr][nc] += share;
            room[r][c] -= share;
        }
        dust.pop();
    }
}

static void _air_purifier(void) {
    int nr, nc, ddr, ddc;

    nr = pure_1 - 1; nc = 0;
    ddr = -1; ddc = 0;
    while (true) {
        if (nr == pure_1 && nc == 0) {
            break;
        } else if (nr == 0 && nc == 0) {
            ddr = 0; ddc = 1;
        } else if (nr == 0 && nc == C - 1) {
            ddr = 1; ddc = 0;
        } else if (nr == pure_1 && nc == C - 1) {
            ddr = 0; ddc = -1;
        }
        room[nr][nc] = room[nr + ddr][nc + ddc];
        nr += ddr; nc += ddc;
    }
    room[pure_1][1] = 0;

    nr = pure_2 + 1; nc = 0;
    ddr = 1; ddc = 0;
    while (true) {
        if (nr == pure_2 && nc == 0) {
            break;
        } else if (nr == R - 1 && nc == 0) {
            ddr = 0; ddc = 1;
        } else if (nr == R - 1 && nc == C - 1) {
            ddr = -1; ddc = 0;
        } else if (nr == pure_2 && nc == C - 1) {
            ddr = 0; ddc = -1;
        }
        room[nr][nc] = room[nr + ddr][nc + ddc];
        nr += ddr; nc += ddc;
    }
    room[pure_2][1] = 0;
}

static void _syncronized(void) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            temp[r][c] = room[r][c];
        }
    }
}

static void _cal_amount_of_dust(void) {
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            if (room[r][c] > 0)
                cnt += room[r][c];
}
