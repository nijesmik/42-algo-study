#include <iostream>
#include <sstream>
using namespace std;
string str;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> str;
	stringstream ss(str);
	string s;
	string temp;
	int cnt = 0;
	int len = 0;
	bool flag = false;
	while (getline(ss, s, ':'))
	{
		len += s.length();
		cnt++;
		if (!flag && s.length() == 0)
		{
			flag = true;
			int c_cnt = 0;
			for (int i = len - 1; i >= 0; i--)
			{
				if (str[i] == ':')
					c_cnt++;
			}
			for (int i = len + 1; i < str.length(); i++)
			{
				if (str[i] == ':')
					c_cnt++;
			}
			if (c_cnt == 1 && str[str.length() - 1] == ':' && str[0] == ':')
			{
				c_cnt--;
			}
			if (c_cnt == 1 && str[str.length() - 1] != ':')
			{
				if (str[0] != ':')
					c_cnt++;
			}
			if (c_cnt > 1)
			{
				if (str[0] == ':' && str[len] == ':')
				{
					cnt -= 2;
				}
				else if (c_cnt != 2 && str[str.length() - 1] != ':')
				{
					c_cnt++;
					cnt--;
				}
				else if (c_cnt == 2 && str[str.length() - 1] != ':')
				{
					int cc = 0;
					for (int i = str.length() - 1; i >= 0; i--)
					{
						if (str[i] == ':')
							cc++;
					}
					if (cc == 3)
					{
						c_cnt++;
						cnt--;
					}
				}
			}
			while (c_cnt++ != 8)
			{
				temp += "0000";
				cnt++;
				if (cnt <= 8)
					temp += ":";
			}
		}
		else
		{
			if (s.length() == 0)
				continue;
			for (int i = s.length(); i < 4; i++)
				temp += "0";
			temp += s;
			if (cnt < 8)
				temp += ":";
		}
		len++;
	}
	cout << temp;
	return (0);
}