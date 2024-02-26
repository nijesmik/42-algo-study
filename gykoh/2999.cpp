#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int N, R, C;
int main()
{
	string msg;
	cin >> msg;
	N = msg.length();
	for (int i = sqrt(N); i >= 1; i--) {
		if (N % i == 0) {
			R = i;
			C = N / R;
			break ;
		}
	}

	char arr[R][C];
	int idx = 0;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			arr[j][i] = msg[idx];
			idx++;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
	}
	return 0;
}
