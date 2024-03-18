#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

string str, buf, ans;
vector<string> words;

bool IsCpp(string str)
{
    for (auto e : str)
	{
		if (e == '_')
			return true;
	}
    return false;
}

int main() 
{
    bool first = true;
    
	cin >> str;

    if (!islower(str[0]))
	{
        cout << "Error!";
        return 0;
    }
    if (str[str.size()-1] == '_')
	{
        cout << "Error!";
        return 0;
    }
    if (IsCpp(str))
	{
        istringstream ss(str);
        
		while (getline(ss, buf, '_'))
            words.push_back(buf);

        for (auto w : words)
		{
            if (islower(w[0]))
			{
                if (first)
                    first = false;
                else 
                    w[0] = toupper(w[0]);
                ans += w;
            }
            else
			{
                cout << "Error!";
                return 0;
            }
            for (int i = 1; i < w.size(); i++)
			{
                if (isupper(w[i]))
				{
                    cout << "Error!";
                    return 0;
                }
            }
        }
    }
    else
	{
        for (auto e : str)
		{
            if (isupper(e))
			{
                ans += buf;
                ans += '_';
                buf.clear();
                buf += tolower(e);
            }
            else 
                buf += e;
        }
        ans += buf;
    }
    cout << ans;
}
