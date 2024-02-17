#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int N,M,ans;
bool button[10];

bool is_possible(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if (button[s[i] - 48])
            return (false);
    }
    return (true);
}

int main()
{
    cin >> N >> M;
    int input;
    for(int i = 0; i < M; i++)
    {
        cin >> input;
        button[input] = true;
    }
    if (N == 100)
    {
        cout << "0";
        return (0);
    }
    ans = abs(N - 100);
    int temp;
    for (int i = 0; i <= 1000000; i++)
    {
        string s = to_string(i);
        if (is_possible(s))
        {
            temp = abs(N - i) + s.size();
            ans = min(ans, temp);
        }
    }
    cout << ans;
    return (0);
}