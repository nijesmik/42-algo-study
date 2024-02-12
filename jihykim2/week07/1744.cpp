#include <iostream>
#include <algorithm>
using namespace std;

int N, seq[50], s, sum;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> seq[i];
    sort(seq, seq + N);

    s = 0;
    while (s + 1 < N && seq[s] < 0 && seq[s + 1] <= 0) {
        sum += seq[s] * seq[s + 1];
        s += 2;
    }
    while (s < N && seq[s] <= 1)
        sum += seq[s++];
    --N;        // 마지막 인덱스는 N - 1 부터 시작
    while (N > s) {
        sum += seq[N] * seq[N - 1];
        N -= 2;
    }
    if (N == s)
        sum += seq[N];
    cout << sum;
    return 0;
}

/** [풀이 과정]
 * 벡터로 받아서 sort로 정렬
 * 0을 만날때까지 음수끼리 묶고, 음수가 남아있다면 0과 묶고, 양수끼리 뒤에서부터 묶는다
 * 라고만 생각했는데, 0과 1인 경우 예외상황이 있었다
   - 0과 음수가 만나면 묶어야 함 (양수는 묶으면 안됨)
   - 1이 존재하면 묶지 말고 더해야 함
 * 1보다 작거나 같은 값들은 모두 그냥 더했는데 조건을 더 안줘서... sanitize 조건을 걸고 컴파일 시 터짐
*/
