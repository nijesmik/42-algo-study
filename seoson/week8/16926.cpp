#include <iostream>

using namespace std;
int N,M,R;
int arr[301][301];

void    rotate()
{
    int temp[3010][301] = {0,};
    for(int i = 0; i < min(N,M)/2; i++)
    {
        int x1 = i;
        int x2 = N - 1 - i;
        int y1 = i;
        int y2 = M - 1 - i;
        for(int j = x1 + 1; j <= x2; j++)
            temp[j][y1] = arr[j - 1][y1];
        for(int j = x2 - 1; j >= x1; j--)
            temp[j][y2] = arr[j + 1][y2];
        for(int j = y1 + 1; j <= y2; j++)
            temp[x2][j] = arr[x2][j - 1];
        for (int j = y2 - 1; j >= y1; j--)
            temp[x1][j] = arr[x1][j + 1];
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            arr[i][j] = temp[i][j];
        }
    }
}

int main()
{
    cin >> N >> M >> R;
    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    }
    if (R != 0)
    {
        while (R--)
            rotate();
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return (0);
}