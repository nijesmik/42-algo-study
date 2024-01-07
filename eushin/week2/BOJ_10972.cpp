#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, temp;
int permutation[10001];
vector<int> perm;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		perm.push_back(temp);
	}
	if (next_permutation(perm.begin(), perm.end()))
	{
		for (int i = 0; i < N; i++)
			cout << perm[i] << " ";
		cout << "\n";
	}
	else
		cout << "-1\n";
	return 0;
}