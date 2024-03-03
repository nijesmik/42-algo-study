#include <iostream>
#include <string>
using namespace std;
int N;
string pattern, filename;

void Input()
{
	cin >> N >> pattern;
}

void Solution()
{
	int starIndex = pattern.find('*');
	string prePattern = pattern.substr(0, starIndex);
	string posPattern = pattern.substr(starIndex+1);

	while (N--)
	{
		cin >> filename;
		
		string preFilename = filename.substr(0, prePattern.length());
		int len =  filename.length() - prePattern.length() - posPattern.length();
		
		if(len < 0)
		{
			cout << "NE\n";
			continue;
		}
		
		string posFilename = filename.substr(filename.length() - posPattern.length());

		if (prePattern.compare(preFilename) == 0)
		{
			if (posPattern.compare(posFilename) == 0)
			{
				cout << "DA\n";
				continue;
			}
		}
		cout << "NE\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
