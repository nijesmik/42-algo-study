#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int alphabet[26] = {
	3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
vector<int> name_board;
string name_A, name_B;

void Input()
{
	cin >> name_A >> name_B;
}

void Solution()
{
	for (int i = 0; i < name_A.length(); i++)
	{
		int idx = name_A[i];
		name_board.push_back(alphabet[idx-65]);
		idx = name_B[i];
		name_board.push_back(alphabet[idx-65]);
	}

	while (true)
	{
		if (name_board.size() == 2)
			break ;
		for (int i = 0; i < name_board.size() - 1; i++)
		{
			name_board[i] = (name_board[i] + name_board[i+1]) % 10;
		}
		name_board.pop_back();
	}
	cout << name_board[0] << name_board[1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
