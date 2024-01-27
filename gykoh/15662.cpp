#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int k;
	cin >> k;
	while (k--)
	{
		int num, dir;
		cin >> num >> dir;
		num--;
		vector<int> d(n);
		d[num] = dir;
		for (int i = num - 1; i >= 0; i--)
		{
			if (a[i][2] != a[i + 1][6])
				d[i] = -d[i + 1];
			else
				break;
		}
		for (int i = num + 1; i < n; i++)
		{
			if (a[i-1][2] != a[i][6])
				d[i] = -d[i-1];
			else
				break;
		}
		for (int i = 0; i < n; i++)
		{
			if (d[i] == 0)
				continue;
			if (d[i] == 1)
			{
				char tmp = a[i][7];
				for (int j = 7; j >= 1; j--)
					a[i][j] = a[i][j - 1];
				a[i][0] = tmp;
			}
			else if (d[i] == -1)
			{
				char tmp = a[i][0];
				for (int j = 0; j < 7; j++)
					a[i][j] = a[i][j+1];
				a[i][7] = tmp;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i][0] == '1')
			ans += 1;
	cout << ans << '\n';
	return 0;
}
