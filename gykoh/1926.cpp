#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int picture[501][501];
int visited[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int start_x, int start_y) {
	int size = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = 1;

	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		size++;

		for (int i = 0; i < 4; i++) {
			int nex_x = current.first + dx[i];
			int new_y = current.second + dy[i];

			if (nex_x >= 0 && nex_x < n && new_y >= 0 && new_y < m
				&& !visited[nex_x][new_y] && picture[nex_x][new_y] == 1) {
				visited[nex_x][new_y] = 1;
				q.push(make_pair(nex_x, new_y));
			}
		}
	}
	return size;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> picture[i][j];
		}
	}
	int region_cnt = 0;
	int max_size = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (picture[i][j] == 1 && !visited[i][j]) {
				int size = bfs(i, j);
				if (size > max_size) {
					max_size = size;
				}
				region_cnt++;
			}
		}
	}
	cout << region_cnt << endl;
	cout << max_size << endl;
	return 0;
}
