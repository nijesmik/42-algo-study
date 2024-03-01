#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n_a,n_b,cnt;
vector<int> a;
vector<int> b;
vector<int> c;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n_a >> n_b;
	int temp;
	for(int i = 0; i < n_a; i++)
	{
		cin >> temp;
		a.push_back(temp);
	}
	for(int i = 0; i < n_b; i++)
	{
		cin >> temp;
		b.push_back(temp);
	}
	sort(b.begin(), b.end());
	for(int i = 0; i < a.size(); i++)
	{
		if (!binary_search(b.begin(), b.end(), a[i]))
		{
			cnt++;
			c.push_back(a[i]);
		}
	}
	sort(c.begin(), c.end());
	cout << cnt << "\n";
	for(int i = 0; i < c.size(); i++)
		cout << c[i] << " ";
	return (0);
}