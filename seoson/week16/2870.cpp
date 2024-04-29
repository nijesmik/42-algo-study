#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N;
vector<string> vec;

bool cmp(string &a, string &b)
{
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		string temp = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (isdigit(str[i]))
			{
				temp += str[i];
			}
			else
			{
				if (temp != "")
				{
					string t = "";
					for (int j = 0; j < temp.length(); j++)
					{
						if (t == "" && temp[j] == '0')
							continue;
						t += temp[j];
					}
					if (t == "")
						t += '0';
					temp = "";
					vec.push_back(t);
				}
			}
		}
		if (temp != "")
		{
			string t = "";
			for (int j = 0; j < temp.length(); j++)
			{
				if (t == "" && temp[j] == '0')
					continue;
				t += temp[j];
			}
			if (t == "")
				t += '0';
			vec.push_back(t);
		}
	}
	sort(vec.begin(), vec.end(), cmp);
	for (auto i : vec)
		cout << i << "\n";
	return (0);
}