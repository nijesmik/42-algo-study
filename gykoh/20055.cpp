#include <iostream>
#include <deque>
using namespace std;

int N, K;
int cycle;
int zero_dur_cnt;

deque<int> durability;
deque<bool> robot;

int main() 
{
    cin >> N >> K;
    durability.resize(2 * N);
    robot.resize(2 * N);
    for (int i = 0; i < 2 * N; i++) 
	{
        cin >> durability[i];
        if (durability[i] == 0)
            zero_dur_cnt++;
    }
    while (true) 
    {
        int lastDurability = durability.back();
        durability.pop_back();
        durability.push_front(lastDurability);
        bool lastRobot = robot.back();
        robot.pop_back();
        robot.push_front(lastRobot);
        robot[N - 1] = false;

        for (int i = N - 2; i >= 0; i--) 
		{
            if (robot[i] && !robot[i + 1] && durability[i + 1] > 0) 
            {
                robot[i] = false;
                robot[i + 1] = true;
                durability[i + 1]--;
                if (durability[i + 1] == 0)
                    zero_dur_cnt++;
            }
        }
        robot[N - 1] = false;

        if (durability[0] > 0) 
        {
            robot[0] = true;
            durability[0]--;
            if (durability[0] == 0)
                zero_dur_cnt++;
        }
		
        cycle++;
        if (zero_dur_cnt >= K)
            break ;
    }
    cout << cycle << endl;
    return (0);
}
