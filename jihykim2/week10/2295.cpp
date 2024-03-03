#include <iostream>
#include <algorithm>
using namespace std;

int N, U[1000], Sum[1000000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int n = 0; n < N; ++n)
        cin >> U[n];

    int sumSize = 0;
    for (int a = 0; a < N; ++a)
        for (int b = a; b < N; ++b)
            Sum[sumSize++] = U[a] + U[b];   // a == b
    sort(Sum, Sum + sumSize);

    for (int d = N - 1; d >= 0; --d) {
        for (int c = d; c >= 0; --c) {
            if (binary_search(Sum, Sum + sumSize, U[d] - U[c]) == true) {
                cout << U[d];
                return 0;
            }
        }
    }

    return 0;
}
/**
 * (a + b + c) = d
 * (a + b) = (d - c)
*/
