#include <iostream>
using namespace std;

int N;
long X, cnt;
pair<long, long> burger[51];

int main(void) {
    cin >> N >> X;

    burger[0].first = 1; burger[0].second = 1;
    for (int i = 1; i <= N; i++) {
        burger[i].first = burger[i - 1].first * 2 + 3;
        burger[i].second = burger[i - 1].second * 2 + 1;
    }

    while (true)
    {
        if (X == 1) {
            if (N == 0)
                cnt++;
            break ;
        }
        else if (X == burger[N].first) {
            cnt += burger[N].second;
            break;
        }
        if (X < burger[N - 1].first + 2) {
            X--;
        } else if (X == burger[N - 1].first + 2) {
            cnt += burger[N - 1].second + 1;
            break;
        } else {
            X -= (burger[N - 1].first + 2);
            cnt += burger[N - 1].second + 1;
        }
        N--;
    }

    cout << cnt;
    return 0;
}

/*
0(1, 1):    p
1(5, 3):    1 + (p) + p + (p) + 1
2(13, 7):   1 + {1 + (p) + p + (p) + 1} + p + {1 + (p) + p + (p) + 1} + 1
3(29, 15):  1 + [1 + {1 + (p) + p + (p) + 1} + p + {1 + (p) + p + (p) + 1} + 1] + p + [1 + {1 + (p) + p + (p) + 1} + p + {1 + (p) + p + (p) + 1} + 1] + 1

n번째 햄버거의 층: (n - 1) * 2 + 3
n번째 패티의 수: (n - 1) * 2 + 1
*/
