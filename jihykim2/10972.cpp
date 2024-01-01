#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int			N, n;
vector<int>	Per;

bool	my_solution(void);				// my solution
void	use_next_permutation(void);		// using next_permutation function (for checking)

int	main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		Per.push_back(n);
	}

	if (my_solution() == false)
		cout << -1 << endl;
	else
		for (auto const &element: Per)
			cout << element << " ";

	// use_next_permutation();
	return (0);
}

void	use_next_permutation(void)
{
	if (next_permutation(Per.begin(), Per.end()) == true)
		for (auto const &element: Per)
			cout << element << " ";
	else
		cout << -1 << endl;
}

bool	my_solution(void)
{
	int	swap_index = N;

	while (--swap_index)
		if (Per.at(swap_index) > Per.at(swap_index - 1))
			break ;
	if (swap_index == 0)
		return (false);

	swap_index--;
	for (int i = N - 1; i > swap_index; i--)
		if (Per.at(i) > Per.at(swap_index))
		{
			swap(Per.at(i), Per.at(swap_index));
			break ;
		}
	sort(Per.begin() + swap_index + 1, Per.end());
	return (true);
}

/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 3 2
2 1 3 4
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1

1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3
1 3 2 4 5
1 3 4 2 5
1 3 4 5 2
1 3 5 2 4
1 3 5 4 2
1 4 2 3 5
1 4 3 2 5
1 4 3 5 2
1 4 5 3 2

6 2 4 1 5 3

*/
