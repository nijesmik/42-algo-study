#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
vector <int> A;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	sort(A.begin(), A.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int value;
		cin >> value;
		cout << binary_search(A.begin(), A.end(), value) << "\n";
	}
}