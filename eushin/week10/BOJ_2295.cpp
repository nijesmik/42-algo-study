#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> U, maxValues;
int combination[3];

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		U.push_back(tmp);
	}
}

void Combination(int index, int depth)
{
	if (depth == 3)
	{
		int d = 0;
		for (int i = 0; i < 3; i++)
			d += combination[i];
		if(binary_search(U.begin(), U.end(), d))
			maxValues.push_back(d);
		return ;
	}
	else
	{
		for (int i = index; i < N; i++)
		{
			combination[depth] = U[i];
			Combination(i, depth+1);
		}
	}
}

void Solution()
{
	Combination(0, 0);
	sort(maxValues.begin(), maxValues.end(), greater<>());
	cout << maxValues[0];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
