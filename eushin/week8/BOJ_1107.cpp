#include <iostream>
#include <algorithm>
using namespace std;
int target, broken;
bool button[10];

int possible(int n)
{
    if(n == 0)
    {
        if(button[n])
            return 0;
        else
            return 1;
    }
    
    int len = 0;
    while(n > 0)
    {
        if(button[n%10])
            return 0;
        len += 1;
        n /= 10;
    }
    return len;
}

void Input()
{
    cin >> target;
    cin >> broken;
    
    if (broken > 0)
    {
        for (int i = 0; i < broken; i++)
        {
            int num;
            cin >> num;
            button[num] = true;
        }
    }
}

void Solution()
{
    int ans = abs(target - 100);
    for(int i = 0; i <= 1000000; i++)
    {
        int x = i;
        int len = possible(x);
        
        if (len > 0)
        {
            int press = abs(x - target);    
            if (ans > len + press)
                ans = len + press;
        }   
    }
    cout << ans;
}

int main()
{
    Input();
    Solution();
}