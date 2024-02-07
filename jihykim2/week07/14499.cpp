#include <iostream>
#include <algorithm>
using namespace std;

int N, M, r, c, moveCnt, moveDir;
int Map[20][20], dice[7];
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int de[] = {6, 3, 1, 4};
int dw[] = {6, 4, 1, 3};
int ds[] = {6, 5, 1, 2};
int dn[] = {6, 2, 1, 5};

static void _rotate(int* way);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> r >> c >> moveCnt;
    for (int n = 0; n < N; n++)
        for (int m = 0; m < M; m++)
            cin >> Map[n][m];

    while (moveCnt--) {
        cin >> moveDir;
        int nr = r + dr[moveDir - 1], nc = c + dc[moveDir - 1];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if (moveDir == 1)
            _rotate(de);
        else if (moveDir == 2)
            _rotate(dw);
        else if (moveDir == 3)
            _rotate(ds);
        else if (moveDir == 4)
            _rotate(dn);
        else
            continue;
        if (Map[nr][nc] == 0)
            Map[nr][nc] = dice[6];
        else {
            dice[6] = Map[nr][nc];
            Map[nr][nc] = 0;
        }
        r = nr; c = nc;
        std::cout << dice[1] << "\n";
    }

    return 0;
}

static void _rotate(int* way) {
    int tmp = dice[6];
    for (int i = 0; i < 3; ++i) {
        dice[way[i]] = dice[way[i + 1]];
    }
    dice[way[3]] = tmp;
}

/*
         [6]    [1]     [2]    [3]
1: 동 >> [3]    [3]     [3]    [1]
2: 서 >> [4]    [4]     [4]    [6]
3: 남 >> [5]    [5]     [1]    [5]
4: 북 >> [2]    [2]     [6]    [2]

1 2 5 6 >> east(3), west(4)
1 3 4 6 >> north(2), south(5)
2 3 4 5 >> north(1), south(6)
ㄴ> 응 아니야

[6] 응 이거야
동 >> 6 > 3 > 1 > 4 > 6
서 >> 6 > 4 > 1 > 3 > 6
남 >> 6 > 5 > 1 > 2 > 6
북 >> 6 > 2 > 1 > 5 > 6
*/
