# include <iostream>
# include <algorithm>
using namespace std;
int K, N, num;
long long low, mid, high;
int arr[10001];

int main()
{
    cin >> K >> N;
    
    for (int i = 0; i < K; i++)
        cin >> arr[i];
        
    sort(arr, arr + K); 
    high = arr[K - 1];
    mid = (low + high) / 2;

    while (low <= high)
    {
        num = 0;
        for (int i = 0; i < K; i++)
        {
            if (mid == 0)
                mid = 1;
            num += arr[i] / mid;
        }
        if (num < N)
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if(N == 1)
        cout << arr[0];
    else
        cout << mid;   
}