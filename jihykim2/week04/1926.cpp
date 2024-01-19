#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[500][500];
bool visited[500][500] = { false, };
int n, m, picture_cnt, picture_max;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int, int>> que;

int main(void)
{
    cin >> n >> m;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> map[r][c];
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (visited[r][c] == true || map[r][c] == 0) continue;

            que.push(make_pair(r, c));
            visited[r][c] = true;

            picture_cnt++;
            int picture_area = 0;
            while (que.empty() == false) {
                picture_area++;
                int curr_r = que.front().first;
                int curr_c = que.front().second;
                que.pop();
                for (int i = 0; i < 4; i++) {
                    int check_r = curr_r + dr[i];
                    int check_c = curr_c + dc[i];
                    if (check_r < 0 || check_r >= n || check_c < 0 || check_c >= m) continue;
                    if (visited[check_r][check_c] == true ||  map[check_r][check_c] == 0) continue;
                    visited[check_r][check_c] = true;
                    que.push(make_pair(check_r, check_c));
                }
            }
            if (picture_area > picture_max) picture_max = picture_area;
        }
    }
    cout << picture_cnt << "\n" << picture_max;
    return 0;
}
