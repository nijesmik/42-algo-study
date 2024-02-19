#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(void){

  int N;
	vector<vector<int>> score(50, vector<int>(9));
	int ans = 0;

    vector<int> player = {1, 2, 3, 4, 5, 6, 7, 8};

    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < 9; j++){
            cin >> score[i][j];
        }
    }

    do {
        int sum = 0;
        int index = 0;
        vector<int> tmp_player = player;

        tmp_player.insert(tmp_player.begin() + 3, 0);

				for (int inning = 0; inning < N; inning++){
          int out = 0;
          queue<int> base;

            while (out != 3){
                int state = score[inning][tmp_player[index++]];

                if (state == 0){
                    out++;
                }
                else if (state == 1){
                    if(base.empty()){
                        base.push(0);
                        base.push(0);
                        base.push(1);
                    }
                    else {
                        if(base.size() == 3){
                            sum += base.front();
                            base.pop();
                        }
                        base.push(1);
                    }
                }
								else if (state == 2){
                    if (base.empty()){
                        base.push(0);
                        base.push(1);
                        base.push(0);
                    }
                    else{
                        if (base.size() == 3){
                            for (int i = 0; i < 2; i++){
                                sum += base.front();
                                base.pop();
                            }
                        }
                        base.push(1);
                        base.push(0);
                    }
                }
								else if (state == 3){
                    if (base.empty()){
                        base.push(1);
                        base.push(0);
                        base.push(0);
                    }
                    else {
                        if (base.size() == 3){
                            for (int i = 0; i < 3; i++){
                                sum += base.front();
                                base.pop();
                            }
                        }
                        base.push(1);
                        base.push(0);
                        base.push(0);
                    }
                }
                else if (state == 4){
                    while (!base.empty()){
                        sum += base.front();
                        base.pop();
                    }
                    sum++;
                }

								if (index == 9){
                    index = 0;
                }
            }
        }
				ans = ans < sum ? sum : ans;
    }
		while(next_permutation(player.begin(), player.end()));
    cout << ans;
    return 0;
}
