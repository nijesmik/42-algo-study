#include <iostream>
#include <algorithm>
using namespace std;

int N;
int max_cnt;
char candy[51][51];

void cnt_candy() {
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N; j++) {
			if (candy[i][j] == candy[i][j + 1]) {
				cnt++;
			}
			else {
				if (max_cnt < cnt) {
					max_cnt = cnt;
				}
				cnt = 1;
			}
		}
	}
	for (int j = 0; j < N; j++) {
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			if (candy[i][j] == candy[i + 1][j]) {
				cnt++;
			}
			else {
				if (max_cnt < cnt) {
					max_cnt = cnt;
				}
				cnt = 1;
			}
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> candy[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            swap(candy[i][j], candy[i][j + 1]);
            cnt_candy();
            swap(candy[i][j], candy[i][j + 1]);
        }
    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N - 1; i++) {
            swap(candy[i][j], candy[i + 1][j]);
            cnt_candy();
            swap(candy[i][j], candy[i + 1][j]);
        }
    }
		cout << max_cnt << endl;
}
