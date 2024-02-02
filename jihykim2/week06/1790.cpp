#include <iostream>
using namespace std;

int N, k, digit = 9, unit = 1, startNum = 1, numValue, modValue;

int main(void) {
    cin >> N >> k;
    if (k <= 9) {
        cout << k;
        return 0;
    }
    while (true) {
        if (k <= digit * unit)
            break;
        k -= digit * unit;
        startNum += digit;
        digit *= 10;
        unit++;
    }
    modValue = k % unit;
    if (modValue == 0) {
        modValue = unit;
        startNum--;
    }
    numValue = startNum + (k / unit);
    if (numValue > N) {
        cout << -1;
        return 0;
    }
    for (int i = modValue; i < unit; i++)
        numValue /= 10;
    cout << numValue % 10;
    return 0;
}

/*
9: (9 - 1) + 1
90: (99 - 10) + 1
900: (999 - 100) + 1

123456789 10 11 12 13 14 15 16 17 18 1920212223...
20 23 -> 6

[204]
9 + 90 = 99 (9 + 180 = 189)
(100 101 102 103 104 105 106 107)

204 - 189 = 15
15 % 3 = 0
15 / 3 = 5
*/