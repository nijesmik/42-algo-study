#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, Score;
int All;
int Class[20][20];
vector<pair<int, int>> Student;     // Student, Love: index 공유 (student num, index)
vector<vector<int>> Love;           // Student, Love: index 공유
int row, col, lov, emp;

static bool _condition_refresh(int r, int c, int n, int& lov_cnt, int& emp_cnt);
static void _check(int now, int& lov_cnt, int& emp_cnt, int n);
static bool _is_love(int student_num, int n);

int main(void)
{
    cin >> N;
    All = N * N;
    int num, a,  b, c, d;
    for (int i = 0; i < All; i++)
    {
        cin >> num >> a >> b >> c >> d;
        Student.push_back(make_pair(num, i));
        Love.push_back({a, b, c, d});
    }

    Class[1][1] = Student[0].first;
    for (int n = 1; n < All; n++)
    {
        row = 30; col = 30; lov = 0; emp = 0;
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                if (Class[r][c] != 0)   // 이미 다른 학생이 앉아있음
                    continue;
                int lov_cnt = 0, emp_cnt = 0;
                if (_condition_refresh(r, c, n, lov_cnt, emp_cnt) == true)
                {
                    row = r;
                    col = c;
                    lov = lov_cnt;
                    emp = emp_cnt;
                }
            }
        }
        Class[row][col] = Student[n].first;
    }

    sort(Student.begin(), Student.end());
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            int now = Class[r][c];
            int happy_cnt = 0;
            if (r > 0 && _is_love(Class[r - 1][c], Student[now - 1].second) == true)
                happy_cnt++;
            if (c > 0 && _is_love(Class[r][c - 1], Student[now - 1].second) == true)
                happy_cnt++;
            if (r < N - 1 && _is_love(Class[r + 1][c], Student[now - 1].second) == true)
                happy_cnt++;
            if (c < N - 1 && _is_love(Class[r][c + 1], Student[now - 1].second) == true)
                happy_cnt++;
            if (happy_cnt > 0)
                Score += pow(10, happy_cnt - 1);
        }
    }

    cout << Score;

    return 0;
}

static bool _condition_refresh(int r, int c, int n, int& lov_cnt, int& emp_cnt)
{
    if (r > 0)
        _check(Class[r - 1][c], lov_cnt, emp_cnt, n);
    if (c > 0)
        _check(Class[r][c - 1], lov_cnt, emp_cnt, n);
    if (r < N - 1)
        _check(Class[r + 1][c], lov_cnt, emp_cnt, n);
    if (c < N - 1)
        _check(Class[r][c + 1], lov_cnt, emp_cnt, n);

    if (lov_cnt > lov)
        return true;
    else if (lov_cnt == lov && emp_cnt > emp)
        return true;
    return false;
}

static void _check(int now, int& lov_cnt, int& emp_cnt, int n)
{
    if (now == 0)
        emp_cnt++;
    else if (_is_love(now, n) == true)
        lov_cnt++;
}

static bool _is_love(int student_num, int n)
{
    for (int i = 0; i < 4; i++)
        if (Love[n][i] == student_num)
            return true;
    return false;
}

/*
 * 반례 (실패): 답은 45
3
1 2 3 4 5
2 3 4 5 6
3 1 4 5 6
4 5 6 7 8
5 1 3 4 6
6 4 5 7 8
7 1 2 8 9
8 3 4 7 9
9 5 6 7 8
*/
