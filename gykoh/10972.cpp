#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main()
{
	cin >> N;
	vector<int> permutation(N);
	for (int i = 0; i < N; i++)
		cin >> permutation[i];
	int i = N - 2;
	while (i >= 0 && (permutation[i] >= permutation[i + 1]))
		i--;
	if (i < 0)
	{
		cout << -1 << endl;
		return (0);
	}
	int j = N - 1;
	while (permutation[i] >= permutation[j])
		j--;
	swap(permutation[i], permutation[j]);
	sort(permutation.begin() + i + 1, permutation.end());
	for (int i = 0; i < permutation.size(); i++) 
    	cout << permutation[i] << ' ';
    cout << endl;
	return (0);
}
