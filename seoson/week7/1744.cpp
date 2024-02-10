#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
long long N,ans,zero_cnt;
deque<int> pos_deq;
deque<int> neg_deq;
int main()
{
	int input;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> input;
		if (input > 0)
			pos_deq.push_back(input);
		else if (input < 0)
			neg_deq.push_back(input);
		else
			zero_cnt++;
	}
	sort(pos_deq.rbegin(), pos_deq.rend());
	sort(neg_deq.begin(), neg_deq.end());
	while (!pos_deq.empty()) {
		int temp = pos_deq.front();
		pos_deq.pop_front();
		if (temp > 1 && !pos_deq.empty() && pos_deq.front() > 1) {
			ans += temp * pos_deq.front();
			pos_deq.pop_front();
		} else {
			ans += temp;
		}
	}
	while(!neg_deq.empty()) {
		int temp = neg_deq.front();
		neg_deq.pop_front();
		if (!neg_deq.empty()) {
			ans += temp * neg_deq.front();
			neg_deq.pop_front();
		}
		else if (!zero_cnt) {
			ans += temp;
		}
	}
	cout << ans;
	return (0);
}