#include <iostream>
#include <vector>
using namespace std;
string A,B;
vector<int>	vec;
vector<int>	vec_2;
int arr[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	cin >> A >> B;
	for(int i = 0 ; i < A.length(); i++)
	{
		vec.push_back(arr[A[i]-'A']);
		vec.push_back(arr[B[i]-'A']);
	}
	while(vec.size() != 2)
	{
		vec_2.clear();
		for(int i = 1; i < vec.size(); i++)
			vec_2.push_back((vec[i - 1] + vec[i]) % 10);
		vec.clear();
		vec = vec_2;
	}
	cout << vec[0] << vec[1];
	return (0);
}