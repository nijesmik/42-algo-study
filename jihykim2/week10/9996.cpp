#include <iostream>
using namespace std;

int N, frontLen, backLen;
string pattern, front, back, compStr;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> pattern;

    int starIdx = pattern.find('*');
    front = pattern.substr(0, starIdx);
    back = pattern.substr(starIdx + 1);
    frontLen = front.length();
    backLen = back.length();

    while (N--) {
        cin >> compStr;
        if (compStr.length() < frontLen + backLen) {
            cout << "NE-------\n";
            continue ;
        }
        if (compStr.substr(0, frontLen) == front && compStr.substr(compStr.length() - backLen) == back) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }
    return 0;
}