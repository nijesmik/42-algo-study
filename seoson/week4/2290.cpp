#include <iostream>
#include <queue>
using namespace std;
int s;
int garo,sero;
string n;
queue <char> q;
void	print()
{
	for(int i = 0; i < sero; i++)
	{
		for(int j = 0; j < n.length(); j++)
		{
			if (i == 0)
			{
				for(int k = 0; k < garo + 1; k++)
				{
					if (n[j] == '1' || n[j] == '4')
						q.push(' ');
					else
					{
						if (k == 0 || k == garo || k == garo - 1)
							q.push(' ');
						else
							q.push('-');
					}
				}
			}
			else if (i == sero - 1)
			{
				for(int k = 0; k < garo + 1; k++)
				{
					if (n[j] == '1' || n[j] == '4' || n[j] == '7')
						q.push(' ');
					else
					{
						if (k == 0 || k == garo || k == garo - 1)
							q.push(' ');
						else
							q.push('-');
					}
				}
			}
			else if (i == sero / 2)
			{
				for(int k = 0; k < garo + 1; k++)
				{
					if (n[j] == '1' || n[j] == '7' || n[j] == '0')
						q.push(' ');
					else
					{
						if (k == 0 || k == garo || k == garo - 1)
							q.push(' ');
						else
							q.push('-');
					}
				}
			}
			else if (i < sero / 2)
			{
				for(int k = 0; k < garo + 1; k++)
				{
					if (n[j] == '1' || n[j] == '2' || n[j] == '3' || n[j] == '7')
					{
						if (k == garo - 1)
							q.push('|');
						else
							q.push(' ');
					}
					else if (n[j] == '5' || n[j] == '6')
					{
						if (k == 0)
							q.push('|');
						else
							q.push(' ');
					}
					else
					{
						if (k == 0 || k == garo - 1)
							q.push('|');
						else
							q.push(' ');
					}
				}
			}
			else
			{
				for(int k = 0; k < garo + 1; k++)
				{
					if (n[j] == '1' || n[j] == '3' || n[j] == '4' || n[j] == '5' || n[j] == '7' || n[j] == '9')
					{
						if (k == garo - 1)
							q.push('|');
						else
							q.push(' ');
					}
					else if (n[j] == '2')
					{
						if (k == 0)
							q.push('|');
						else
							q.push(' ');
					}
					else
					{
						if (k == 0 || k == garo - 1)
							q.push('|');
						else
							q.push(' ');
					}
				}
			}
		}
		while (!q.empty())
		{
			cout << q.front();
			q.pop();
		}
		cout << "\n";
	}
}

int main()
{
	cin >> s >> n;
	garo = s + 2;
	sero = 2 * s + 3;
	print();
	return (0);
}