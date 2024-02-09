#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, result;
bool zero_exist;
vector<int> pos, neg;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp > 1)
			pos.push_back(tmp);
		else if (tmp < 0)
			neg.push_back(tmp);
		else if (tmp == 0)
			zero_exist = true;
		else if (tmp == 1)
			result++;
	}

}

int Solution()
{
	sort(pos.begin(), pos.end(), greater<>());
	sort(neg.begin(), neg.end());

	for (int i = 0; i < pos.size() - (pos.size()%2); i += 2)
	{
		if (pos[i] == 1 || pos[i+1] == 1)
			break;
		result += pos[i] * pos[i+1];
	}
	if (pos.size() % 2 == 1)
		result += pos.back();
	for (int i = 0; i < neg.size() - (neg.size()%2); i += 2)
		result += neg[i] * neg[i+1];
	if (neg.size() % 2 == 1)
	{
		if (zero_exist == false)
			result += neg.back();
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	cout << Solution();
}