#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int max_row = 23;
const int max_col = 12;

void initialize_digits(char digits[][max_row][max_col], int s) 
{
    for (int digit = 0; digit < 10; digit++) 
    {
        for (int i = 0; i < max_row; i++) 
        {
            for (int j = 0; j < max_col; j++) {
                digits[digit][i][j] = ' ';
            }
        }
    }

    for (int i = 0; i < 2 * s + 3; i++) 
    {
        if (i % (s + 1) == 0) 
        {
            if (i / (s + 1) != 1) 
            {
                for (int j = 1; j <= s; j++)
                    digits[0][i][j] = '-';
            }
        } else 
        {
            digits[0][i][0] = '|';
            digits[0][i][s + 1] = '|';
        }
    }

    for (int i = 0; i < 2 * s + 3; i++) 
    {
        if (i % (s + 1) != 0)
            digits[1][i][s + 1] = '|';
    }

    for (int i = 0; i < 2 * s + 3; i++) 
    {
        if (i % (s + 1) == 0) {
            for (int j = 1; j <= s; j++)
                digits[2][i][j] = '-';
        } 
        else 
        {
            if (i / (s + 1) == 0)
                digits[2][i][s + 1] = '|';
            else
                digits[2][i][0] = '|';
        }
    }
    for (int i = 0; i < 2 * s + 3; i++) 
    {
        if (i % (s + 1) == 0) 
        {
            for (int j = 1; j <= s; j++)
                digits[3][i][j] = '-';
        } 
        else 
        {
            digits[3][i][s + 1] = '|';
        }
    }
    for (int i = 0; i < 2 * s + 3; i++) 
    {
        if (i % (s + 1) == 0) 
        {
            if (i / (s + 1) == 1) 
            {
                for (int j = 1; j <= s; j++)
                    digits[4][i][j] = '-';
            }
        } 
        else 
        {
            if (i / (s + 1) == 0) 
            {
                digits[4][i][0] = '|';
                digits[4][i][s + 1] = '|';
            }
            else
                digits[4][i][s + 1] = '|';
        }
    }
    for (int i = 0; i < 2 * s + 3; i++) 
    {
        if (i % (s + 1) == 0) 
        {
            for (int j = 1; j <= s; j++)
                digits[5][i][j] = '-';
        } 
        else 
        {
            if (i / (s + 1) == 0)
                digits[5][i][0] = '|';
            else
                digits[5][i][s + 1] = '|';
        }
    }
    for (int i = 0; i < 2 * s + 3; i++) 
    {
        if (i % (s + 1) == 0) 
        {
            for (int j = 1; j <= s; j++)
                digits[6][i][j] = '-';
        }
        else 
        {
            if (i / (s + 1) == 0)
                digits[6][i][0] = '|';
            else 
            {
                digits[6][i][0] = '|';
                digits[6][i][s + 1] = '|';
            }
        }
    }
    for (int i = 0; i < 2 * s + 3; i++) 
    {
        if (i % (s + 1) == 0) 
        {
            if (i / (s + 1) == 0) 
            {
                for (int j = 1; j <= s; j++)
                    digits[7][i][j] = '-';
            }
        } 
        else
            digits[7][i][s + 1] = '|';
    }
    for (int i = 0; i < 2 * s + 3; i++)
    {
        if (i % (s + 1) == 0)
        {
            for (int j = 1; j <= s; j++)
                digits[8][i][j] = '-';
        }
        else
        {
            digits[8][i][0] = '|';
            digits[8][i][s + 1] = '|';
        }
    }
    for (int i = 0; i < 2 * s + 3; i++) 
    {
        if (i % (s + 1) == 0) 
        {
            for (int j = 1; j <= s; j++)
                digits[9][i][j] = '-';
        }
        else
        {
            if (i / (s + 1) == 0) 
            {
                digits[9][i][0] = '|';
                digits[9][i][s + 1] = '|';
            } 
            else
                digits[9][i][s + 1] = '|';
        }
    }
}

int main(void) 
{
    int s;
    string n;
    cin >> s >> n;

    char digits[10][max_row][max_col];
    initialize_digits(digits, s);
    vector<int> num_store;
    for (int i = 0; i < n.size(); i++)
        num_store.push_back(n[i] - '0');
    for (int row = 0; row < max_row; row++)
    {
        for (int j = 0; j < num_store.size(); j++)
        {
            int digit = num_store[j];
            for (int col = 0; col < s + 2; col++)
                cout << digits[digit][row][col];
            if (j == num_store.size() - 1)
                cout << "\n";
            else
                cout << " ";
        }
    }
    return 0;
}
