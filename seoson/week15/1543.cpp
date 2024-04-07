#include <iostream>
#include <cstring>
using namespace std;
string str;
string f;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	getline(cin,str);
	getline(cin,f);
	int pos=0,cnt=0,len=f.length();
	while(str.find(f, pos) != string::npos)
	{
		pos = str.find(f, pos) + len;
		cnt++;
	}
	cout << cnt;
	return (0);
}