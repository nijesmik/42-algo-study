#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int *num1;

bool binary_search(int target_num)
{
    int start = 0;
    int end = N - 1;

    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (num1[middle] == target_num)
            return true;
        else if (num1[middle] < target_num)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    num1 = new int[N];
    for (int i = 0; i < N; i++)
        cin >> num1[i];
    sort(num1, num1 + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int check_num;
        cin >> check_num;
        cout << binary_search(check_num) << "\n";
    }
    return 0;
}
