#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool is_cpp, is_java;
string str;
vector<char> vec;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '_')
			is_cpp = true;
		if (str[i] >= 'A' && str[i] <= 'Z')
			is_java = true;
	}
	if (is_cpp)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '_')
			{
				if (i == 0 || i == str.length() - 1)
					is_java = true;
				if (i < str.length() - 1)
				{
					if (str[i + 1] == '_')
						is_java = true;
					str[i + 1] = toupper(str[i + 1]);
				}
			}
			else
				vec.push_back(str[i]);
		}
	}
	else if (is_java)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				if (i == 0)
					is_cpp = true;
				vec.push_back('_');
				vec.push_back(tolower(str[i]));
			}
			else
				vec.push_back(str[i]);
		}
	}
	else
	{
		for (int i = 0; i < str.length(); i++)
			vec.push_back(str[i]);
	}
	if (is_java && is_cpp)
	{
		cout << "Error!";
		return (0);
	}
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i];
	return (0);
}