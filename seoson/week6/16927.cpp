#include <iostream>
using namespace std;

int n,m,r;
int arr[301][301];

int main() {

    cin >> n >> m >> r;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=m;j++){
            cin >> arr[i][j];
        }
    }

    while(r--) {
        int d=0,depth=1;
        int cnt = min(n, m) / 2;
        while (cnt--) {
            int tmp = arr[n - d][depth];

            for (int x = n - d; x > depth; x--)
                arr[x][depth] = arr[x - 1][depth];
            for (int y = depth; y < m - d; y++)
                arr[depth][y] = arr[depth][y + 1];
            for (int x = depth; x < n - d; x++)
                arr[x][m - d] = arr[x + 1][m - d];

            for (int y = m - d; y > depth; y--)
			{
                arr[n - d][y] = arr[n - d][y - 1];
                if (y == depth+1) {
                    arr[n - d][y] = tmp;
                }
            }
            depth++;
            d++;
        }
    }
    for(int i=1; i<=n;i++){
        for(int j=1; j<=m;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}