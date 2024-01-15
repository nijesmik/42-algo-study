#include <iostream>
#include <vector>
#include <queue>
using namespace std;

# define MAX 22

int N;
vector<int> students;
bool check[MAX * MAX][MAX * MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[MAX][MAX];

struct info
{
	int x;
	int y;
	int friends_size;
	int blanks_size;
};

struct compare
{
	bool operator()(info a, info b)
	{
		if (a.friends_size == b.friends_size)
		{
			if (a.blanks_size == b.blanks_size)
			{
				if (a.x == b.x)
					return a.y > b.y;
				else
					return a.x > b.x;
			}
			else
				return a.blanks_size < b.blanks_size;
		}
		else
			return a.friends_size < b.friends_size;
	}
};

bool isInRange(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	else
		return false;
}

int get_satisfaction()
{
	int satisfaction = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int student_no = map[i][j];
			int friends_size = 0;

			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (!isInRange(nx, ny))
					continue;
				if (check[student_no][map[nx][ny]] == true)
					friends_size++;
			}
			if (friends_size == 1)
				satisfaction += 1;
			else if (friends_size == 2)
				satisfaction += 10;
			else if (friends_size == 3)
				satisfaction += 100;
			else if (friends_size == 4)
				satisfaction += 1000;
		}
	}
	return satisfaction;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		int student_no;
		cin >> student_no;
		students.push_back(student_no);
		for (int j = 0; j < 4; j++)
		{
			int friend_no;
			cin >> friend_no;
			check[student_no][friend_no] = true;
		}
	}

	for (int s = 0; s < N * N; s++)
	{
		int student_no = students[s];
		priority_queue<info, vector<info>, compare> pq;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] != 0) //자리가 비어있지 않은 경우
					continue;

				int blanks_size = 0;
				int friends_size = 0;

				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (isInRange(nx, ny))
					{
						if (map[nx][ny] == 0)
							blanks_size++;
						else if (check[student_no][map[nx][ny]] == true)
							friends_size++;
					}
				}
				pq.push({i, j, friends_size, blanks_size});
			}
		}
		info info = pq.top();
		map[info.x][info.y] = student_no;
	}
	cout << get_satisfaction();
	return 0;
}

//#include <iostream>
//#include <queue>
//using namespace std;
//int N;
//int like[401][5];
//int seat[21][21];
//int nr[4] = {-1, 1, 0, 0};	// 상하좌우
//int nc[4] = {0, 0, -1, 1};
//
//priority_queue <pair<pair<int, int>, pair<int, int>>> check_seat(int student_idx)
//{
//	priority_queue <pair<pair<int, int>, pair<int, int>>> info;
//	for (int like_st = 1; like_st <= 4; like_st++)
//	{
//		for (int r = 1; r <= N; r++)
//			for (int c = 1; c <= N; c++)
//			{
//				if (seat[r][c] == like[student_idx][like_st])
//
//			}
//	}
//	return info;
//
//}
//
//void put_first(void)
//{
//	if (N % 2 == 0)
//		seat[N/2][N/2] = like[1][1];
//	else
//		seat[N/2 + 1][N/2 + 1] = like[1][1];
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//
//	cin >> N;
//	for (int i = 1; i <= N * N; i++)
//		for (int j = 0; j < 5; j++)
//			cin >> like[i][j];
//	put_first();
//	for (int i = 2; i <= N; i++)
//	{
//		priority_queue <pair<pair<int, int>, pair<int, int>>> info;
//		info = check_seat(i);
//
//	}
//
//
//}