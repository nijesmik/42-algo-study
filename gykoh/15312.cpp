#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
		int i, j, t;
		j = 0;
		int n[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
		string a, b;
		vector<int> v;

		cin >> a >> b;

		for (i = 0; i < a.size(); i++)
		{
				t = n[a[i] - 'A'];
				v.push_back(t);

				t = n[b[i] - 'A'];
				v.push_back(t);
		}

		j = v.size();
		while(j > 2)
		{
				vector<int> v2;
				for (i = 0; i < j - 1; i++)
				{
						t = v[i] + v[i + 1];
						if (t >= 10) t -= 10;
						v2.push_back(t);
				}

				v = v2;
				j--;
		}

		cout << v[0] << v[1] << endl;
}
