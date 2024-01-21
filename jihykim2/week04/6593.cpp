#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int building[30][30][30];
int visited[30][30][30];
int L, R, C, Max;
char tmp;

int dl[6] = {1, -1, 0, 0, 0, 0};
int dr[6] = {0, 0, 1, -1, 0, 0};
int dc[6] = {0, 0, 0, 0, 1, -1};

int main(void) {
    while (true) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)
            return 0;
        fill_n(&visited[0][0][0], L * R * C, 0);
        queue<tuple<int, int, int>> que;
        for (int l = 0; l < L; l++) {
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    cin >> tmp;
                    if (tmp == 'S') {
                        que.push(make_tuple(l, r, c));
                        visited[l][r][c] = 1;
                    } else if (tmp == 'E') {
                        building[l][r][c] = 2;
                    } else if (tmp == '#') {
                        building[l][r][c] = 0;
                    } else {
                        building[l][r][c] = 1;
                    }
                }
            }
        }

        Max = 0;
        while (que.empty() == false)
        {
            int curr_l = get<0>(que.front()), curr_r = get<1>(que.front()), curr_c = get<2>(que.front());
            que.pop();
            for (int i = 0; i < 6; i++) {
                int nl = curr_l + dl[i], nr = curr_r + dr[i], nc = curr_c + dc[i];
                if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if (visited[nl][nr][nc] != 0 || building[nl][nr][nc] == 0) continue;
                if (building[nl][nr][nc] == 2) {
                    Max = visited[curr_l][curr_r][curr_c];
                    break;
                }
                que.push(make_tuple(nl, nr, nc));
                visited[nl][nr][nc] = visited[curr_l][curr_r][curr_c] + 1;
            }
            if (Max != 0)
                break;
        }
        if (Max != 0)
            cout << "Escaped in " << Max << " minute(s).\n";
        else
            cout << "Trapped!\n";
    }

    return 0;
}
