#include <iostream>
using namespace std;

int H, W, X, Y;
int map[1000][1000] = {0, };

int main()
{
    cin >> H >> W >> X >> Y;
    for (int i = 0; i < H + X; i++) 
    {
        for (int j = 0; j < W + Y; j++) 
        {
            cin >> map[i][j];
        }
    }
    for (int i = X; i <= H; i++)
    {
        for (int j = Y; j <= W; j++)
        {
            map[i][j] -= map[i - X][j - Y];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return (0);
}