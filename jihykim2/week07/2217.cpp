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

/** [풀이 과정]
 * priorityqueue를 사용하려다가 sort가 한번만 필요할 것 같아서 일반 배열로 변경
 * for문을 한번 돌면서 현재 위치부터 남은 개수만큼 곱해서 최댓값과 비교해서 갱신하는 형식으로 진행
*/
