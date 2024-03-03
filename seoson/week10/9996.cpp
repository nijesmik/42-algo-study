#include <iostream>
#include <cstring>
using namespace std;
int N;
string str;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	cin.ignore();
	getline(cin, str);
	int pos = str.find("*");
	if (pos == string::npos)
		pos = str.find(" ");
	string front = str.substr(0, pos);
	string back = str.substr(pos + 1, str.length());
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		bool flag = false;
		if (str.length() - 1 > temp.length())
			flag = true;
		for (int j = 0; j < front.length(); j++)
		{
			if (front[j] != temp[j])
				flag = true;
		}
		for (int j = 0; j < back.length(); j++)
		{
			if (back[j] != temp[temp.length() - back.length() +j])
				flag = true;
		}
		if (flag)
		{
			cout << "NE\n";
		}
		else
		{
			cout << "DA\n";
		}
	}
	return (0);
}