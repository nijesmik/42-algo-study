#include <iostream>
#include <cstdlib>
using namespace std;

int N, zero = 200000000, arr[100000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int left = 0, right = N - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) <= abs(zero))
            zero = sum;
        if (sum < 0)
            left++;
        else
            right--;
    }
    cout << zero;
    return 0;
}
