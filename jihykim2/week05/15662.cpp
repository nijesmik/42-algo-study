#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int T, K, cnt;
deque<int> wheel[1000];
vector<pair<int, int>> rotation;

static void _rotate(int num);
static void _rv_rotate(int num);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, r;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> t;
        for (int j = 0; j < 8; j++) {
            wheel[i].push_front(t % 10);
            t /= 10;
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> n >> r;
        rotation.push_back(make_pair(n - 1, r));
    }

    for (int i = 0; i < K; i++) {
        deque<int> directions;
        directions.push_back(rotation[i].second);
        for (int num = rotation[i].first; num < T - 1; num++) {
            if (wheel[num][2] != wheel[num + 1][6])
                directions.push_back(directions.back() * -1);
            else
                directions.push_back(0);
        }
        for (int num = rotation[i].first; num > 0; num--) {
            if (wheel[num][6] != wheel[num - 1][2])
                directions.push_front(directions.front() * -1);
            else
                directions.push_front(0);
        }
        for (int num = 0; num < T; num++) {
            if (directions[num] == 1)
                _rotate(num);
            else if (directions[num] == -1)
                _rv_rotate(num);
        }
    }
    for (int i = 0; i < T; i++)
        if (wheel[i].front() == 1)
            cnt++;
    cout << cnt;

    return 0;
}

static void _rotate(int num) {  // 1
    wheel[num].push_front(wheel[num].back());
    wheel[num].pop_back();

}

static void _rv_rotate(int num) {   // -1
    wheel[num].push_back(wheel[num].front());
    wheel[num].pop_front();
}

/*
덱 배열(톱니바퀴) T개 나열
While (K--) {
    회전 톱니바퀴 회전 및 양 옆들 회전 {
        기준 톱니바퀴에서 양 옆 회전 방향 결정
        각각 회전하면서 그 옆 톱니 회전 방향 결정
    }
}
(K값 직접 건들지 말고 다른 방법 우회)
for (int i=0; i<K; i++)
    if 톱니바퀴[0] == S극
        cnt++
cout << cnt
*/
