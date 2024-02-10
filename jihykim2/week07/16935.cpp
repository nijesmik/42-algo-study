#include <iostream>
using namespace std;

// typedef void (*Func)(void);
int N, M, R, arr[100][100], tmp[100][100];

static void _row_copy(int org, int cpy, bool rotate);
static void _col_copy(int org, int cpy, bool rotate);
static void _quart_row_copy(int start_r, int start_c, bool forward);
static void _quart_col_copy(int start_r, int start_c, bool forward);
static void synchronized(void);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> R;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> arr[r][c];
            tmp[r][c] = arr[r][c];
        }
    }

    int cmd;
    while (R--) {
        cin >> cmd;
        if (cmd == 1) {
            for (int r = 0; r < N; r++)
                _row_copy(r, N - 1 - r, false);
        } else if (cmd == 2) {
            for (int c = 0; c < M; c++)
                _col_copy(c, M - 1 - c, false);
        } else if (cmd == 3) {
            for (int i = 0; i < N; i++)
                _row_copy(i, 5 - i, true);
        } else if (cmd == 4) {
            for (int i = 0; i < N; i++)
                _col_copy(i, 5 - i, true);
        } else if (cmd == 5) {
            _quart_row_copy(0, 0, true);
            // 반씩 4번... 머리 깨질 각
        }
        if (R != 0)
            synchronized();
    }
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++)
            cout << arr[r][c] << " ";
        cout << "\n";
    }
    return 0;
}

static void _row_copy(int org, int cpy, bool rotate) {
    if (rotate == false) {
        for (int i = 0; i < M; i++)
            arr[org][i] = tmp[cpy][i];
    } else {
        for (int i = 0; i < M; i++)
            arr[org][i] = tmp[N - 1 - i][cpy];
    }
}

static void _col_copy(int org, int cpy, bool rotate) {
    if (rotate == false) {
        for (int i = 0; i < N; i++)
            arr[i][org] = tmp[i][cpy];
    } else {
        for (int i = 0; i < N; i++)
            arr[i][org] = tmp[cpy][M - 1 - i];
    }
}

static void _quart_row_copy(int start_r, int start_c, bool forward) {
    int end_r = N, end_c = M;
    if (start_r == 0)
        end_r /= 2;
    if (start_c == 0)
        end_c /= 2;
    if (forward == true) {
        for (int r = start_r; r < end_r; r++)
            for (int c = start_c; c < end_c; c++)
                arr[r][c] = tmp[r][M - 1 - c];
    } else {
        for (int r = start_r; r < end_r; r++)
            for (int c = start_c; c < end_c; c++)
                arr[r][c] = tmp[N - 1 - r][c];
    }
}

static void synchronized(void) {
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            tmp[r][c] = arr[r][c];
}

/**
 * 시간이 너무 오래(2시간 넘음..)걸려서 일단은 하던 곳까지 제출..합니다... 다시 할게유
*/
