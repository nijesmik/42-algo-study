#include <iostream>
#include <algorithm>
using namespace std;

int K, N, cnt;
long LAN;
int cable[10000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> cable[i];
    }
    sort(cable, cable + K);
    long left = 1;
    long right = cable[K - 1];
    long mid;
    while (left <= right) {
        mid = (right + left) / 2;
        cnt = 0;
        for (int i = 0; i < K; i++) {
            cnt += cable[i] / mid;
        }
        if (cnt >= N) {
            LAN = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << LAN;
    return 0;
}
