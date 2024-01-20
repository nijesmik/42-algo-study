#include <iostream>

using namespace std;

int N, Max;
int Schedule[16];
int Cost[16];
int SumTable[17];       // N + 1일까지 가능

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> Schedule[i] >> Cost[i];

    for (int i = 0; i < N; i++)
    {
        int Sum = 0;
        int j = i;
        while (j < N)
        {
            cout << "J: " << j << endl;
            if (j + Schedule[j] > N)
                break ;
            j += Schedule[j];
            Sum += Cost[j];
        }
        cout << "Sum: " << Sum << endl;
        if (Sum > Max)
            Max = Sum;
    }

    cout << Max;
    return 0;
}
