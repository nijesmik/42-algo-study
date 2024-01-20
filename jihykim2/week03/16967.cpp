#include <iostream>
using namespace std;

int N, Max;
int Schedule[16];
int Cost[16];
int SumTable[17];       // N + 1일까지 가능

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> Schedule[i] >> Cost[i];
    }

    for (int day = 1; day <= N; day++) {
        SumTable[day] = max(SumTable[day], SumTable[day - 1]);      // 전 날과 비교해서 최대 값으로 초기화
        if (day + Schedule[day] <= N + 1)                           // 현 날짜를 선택했을 때, 미래의 예상 비용 값을 비교해서 정하기
            SumTable[day + Schedule[day]] = max(SumTable[day + Schedule[day]], SumTable[day] + Cost[day]);
    }

    for (int i = 1; i <= N + 1; i++) {
        Max = max(Max, SumTable[i]);
    }
    cout << Max;
    return 0;
}
