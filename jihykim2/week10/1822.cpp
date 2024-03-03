#include <iostream>
#include <algorithm>
using namespace std;

int sizeA, sizeB, cnt;
int setA[500000], setB[500000], setRes[500000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> sizeA >> sizeB;
    for (int i = 0; i < sizeA; ++i)
        cin >> setA[i];
    for (int i = 0; i < sizeB; ++i)
        cin >> setB[i];
    sort(setA, setA + sizeA);
    sort(setB, setB + sizeB);

    int b = 0;
    for (int a = 0; a < sizeA; ++a) {
        while (b < sizeB && setA[a] > setB[b])
            b++;
        if (setA[a] == setB[b]) {
            cnt++; b++;
            setA[a] = 0;
        }
    }

    cout << sizeA - cnt << "\n";
    if (cnt == sizeA)
        return 0;
    for (int a = 0; a < sizeA; ++a)
        if (setA[a] > 0)
            cout << setA[a] << " ";

    return 0;
}