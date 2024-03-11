#include <iostream>
#include <vector>
using namespace std;
int N;
int arr[1000002];
vector<int> vec;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4; i <= N; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
	}
	vec.push_back(N);
	for(int i = N; i > 1;)
	{
		if (i % 3 == 0)
		{
			if (i % 2 == 0)
			{
				if (arr[i / 3] > arr[i / 2])
					i /= 2;
				else
					i /= 3;
			}
			else if (arr[i / 3] > arr[i - 1])
					i--;
			else
				i /= 3;
			vec.push_back(i);
		}
		else if (i % 2 == 0)
		{
			if (i % 3 == 0)
			{
				if (arr[i / 3] < arr[i / 2])
					i /= 3;
				else
					i /= 2;
			}
			else if (arr[i - 1] < arr[i / 2])
				i--;
			else
				i /= 2;
			vec.push_back(i);
		}
		else
		{
			i--;
			vec.push_back(i);
		}
	}
	cout << arr[N] << "\n";
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	return (0);
}