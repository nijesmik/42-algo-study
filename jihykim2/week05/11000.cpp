// @sejinkim 교수님 전 안찔려요
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lecture;
priority_queue<int, vector<int>, greater<int>> room;
int N, S, T, endtime;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S >> T;
        lecture.push(make_pair(S, T));
    }
    room.push(lecture.top().second);
    lecture.pop();

    while (lecture.empty() == false) {
        if (lecture.top().first >= room.top())
            room.pop();
        room.push(lecture.top().second);
        lecture.pop();
    }

    cout << room.size();
    return 0;
}

/*
4 6
3 8
8 9
6 10
1 3

1 3
1 3
1 3
*/
