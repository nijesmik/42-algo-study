#include <iostream>
#include <algorithm>
using namespace std;

int N, rope[100000], weight;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> rope[i];
    sort(rope, rope + N);
    weight = rope[0] * N;
    for (int r = 1; r < N; r++) {
        int w = rope[r] * (N - r);
        if (w > weight)
            weight = w;
    }
    cout << weight;
    return 0;
}
