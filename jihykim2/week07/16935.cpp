#include <iostream>
using namespace std;

int N, M, R, arr[100][100], tmp[100][100];

static void _row_copy(int org, int cpy, bool rotate);
static void _col_copy(int org, int cpy, bool rotate);
static void _up_down_copy(int col_start, bool forward);
static void _right_left_copy(int row_start, bool forward);
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
            int tmp = N;
            N = M; M = tmp;
            for (int i = 0; i < N; i++)
                _row_copy(i, M - 1 - i, true);
        } else if (cmd == 4) {
            for (int i = 0; i < N; i++)
                _col_copy(i, N - i, true);
            int tmp = N;
            N = M; M = tmp;
        } else if (cmd == 5) {
            _right_left_copy(0, true);
            _up_down_copy(M / 2, true);
            _right_left_copy(N / 2, false);
            _up_down_copy(0, false);
        } else {
            _up_down_copy(0, true);
            _right_left_copy(N / 2, true);
            _up_down_copy(M / 2, false);
            _right_left_copy(0, false);
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
            arr[org][i] = tmp[i][cpy];
    }
}

static void _col_copy(int org, int cpy, bool rotate) {
    if (rotate == false) {
        for (int i = 0; i < N; i++)
            arr[i][org] = tmp[i][cpy];
    } else {
        for (int i = 0; i < M; i++)
            arr[i][org] = tmp[cpy][M - 1 - i];
    }
}

static void _up_down_copy(int col_start, bool forward) {
    int col_end = M;
    if (col_start == 0)
        col_end /= 2;
    if (forward == true) {
        for (int r = N / 2; r < N; r++)
            for (int c = col_start; c < col_end; c++)
                arr[r][c] = tmp[r - N / 2][c];
    } else {
        for (int r = 0; r < N / 2; r++)
            for (int c = col_start; c < col_end; c++)
                arr[r][c] = tmp[r + N / 2][c];
    }
}

static void _right_left_copy(int row_start, bool forward) {
    int row_end = N, end_c = M;
    if (row_start == 0)
        row_end /= 2;
    if (forward == true) {
        for (int r = row_start; r < row_end; r++)
            for (int c = M / 2; c < M; c++)
                arr[r][c] = tmp[r][c - M / 2];
    } else {
        for (int r = row_start; r < row_end; r++)
            for (int c = 0; c < M / 2; c++)
                arr[r][c] = tmp[r][c + M / 2];
    }
}

static void synchronized(void) {
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            tmp[r][c] = arr[r][c];
}

/** [풀이 과정]
 * 시간이 너무 오래(2시간 넘음..)걸려서 일단은 하던 곳까지 제출..합니다... 다시 할게유
 * 1, 2, 5, 6번은 풀었으나 3, 4번은 아직도 해결을 못하겠다
   무작정 cmd 하나 당 하나의 함수로 풀고 싶지 않았는데 결국은 지금 풀이를 보면 그거나 그거나인것 같다
*/
