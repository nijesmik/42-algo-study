#include <iostream>
#include <queue>
#include <vector>
#define MAX 55
using namespace std;

int N, M;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int answer = 0;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

int bfs(int Y, int X) {
	init();
	queue<pair<pair<int, int>, int> > q;
	int cnt = 0;
	visited[Y][X] = true;
	q.push(make_pair(make_pair(Y, X), cnt));

	while (!q.empty()) {
		int cur_y = q.front().first.first;
		int cur_x = q.front().first.second;
		int cur_cnt = q.front().second;
		q.pop();

		if (arr[cur_y][cur_x] == 1) {
			return cur_cnt;
		}

		for (int i = 0; i < 8; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M) && (!visited[next_y][next_x])) {
				visited[next_y][next_x] = true;
				q.push(make_pair(make_pair(next_y, next_x), cur_cnt + 1));
			}
		}
	};

	return 0;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				answer = max(answer, bfs(i, j));
			}
		}
	}
	cout << answer << "\n";

	return 0;

}
