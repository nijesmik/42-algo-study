#include <iostream>
using namespace std;
int H, W, X, Y;
int B[1301][1301];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> H >> W >> X >> Y;

	for (int i = 1; i <= H + X; i++)
	{
		for (int j = 1; j <= W + Y; j++)
		{
			cin >> B[i][j];
			if (i >= X && i <= H && j >= Y && j <= W)
				B[i][j] -= B[i - X][j - Y];
		}
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
			cout << B[i][j] << " ";
		cout << "\n";
	}
}