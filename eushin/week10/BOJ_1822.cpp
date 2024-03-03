#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int nA, nB;
vector<int> A, B, answer;

void Input()
{
	int tmp;
	cin >> nA >> nB;
	for (int i = 0; i < nA; i++)
	{
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < nB; i++)
	{
		cin >> tmp;
		B.push_back(tmp);
	}
}

void Solution()
{
    int start = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < nA; i++)
	{
		answer.push_back(A[i]);
		for (int j = start; B[j] <= A[i] && j < nB; j++)
		{
			if (A[i] == B[j])
			{
				answer.pop_back();
				break;
			}
           start = j;
		}
	}
	cout << answer.size() << "\n";
	for (auto e : answer)
		cout << e << " ";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
