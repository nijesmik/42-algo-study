#include <iostream>
using namespace std;
int s, r, c;
string num;
int print[25][150];

void draw_top(void) {
	for (int i = c + 1; i < c + 1 + s; i++)
		print[0][i] = 2;
}

void draw_middle(void) {
	for (int i = c + 1; i < c + 1 + s; i++)
		print[(2 * s + 3) / 2][i] = 2;
}

void draw_bottom(void) {
	for (int i = c + 1; i < c + 1 + s; i++)
		print[2 * s + 3 - 1][i] = 2;
}

void draw_left_top(void) {
	for (int i = 1; i < 1 + s; i++)
		print[i][c] = 1;
}

void draw_left_bottom(void) {
	for (int i = s + 2; i < s + 2 + s; i++)
		print[i][c] = 1;
}

void draw_right_top(void) {
	for (int i = 1; i < 1 + s; i++)
		print[i][c + s + 1] = 1;
}

void draw_right_bottom(void) {
	for (int i = s + 2; i < s + 2 + s; i++)
		print[i][c + s + 1] = 1;
}

void draw_one(void) {
	draw_right_top();
	draw_right_bottom();
}

void draw_two(void) {
	draw_top();
	draw_right_top();
	draw_middle();
	draw_left_bottom();
	draw_bottom();
}

void draw_three(void) {
	draw_top();
	draw_right_top();
	draw_middle();
	draw_right_bottom();
	draw_bottom();
}

void draw_four(void) {
	draw_left_top();
	draw_right_top();
	draw_middle();
	draw_right_bottom();
}

void draw_five(void) {
	draw_top();
	draw_middle();
	draw_bottom();
	draw_left_top();
	draw_right_bottom();
}

void draw_six(void) {
	draw_top();
	draw_left_top();
	draw_middle();
	draw_left_bottom();
	draw_right_bottom();
	draw_bottom();
}

void draw_seven(void) {
	draw_top();
	draw_right_top();
	draw_right_bottom();
}

void draw_eight(void) {
	draw_top();
	draw_middle();
	draw_bottom();
	draw_right_top();
	draw_right_bottom();
	draw_left_top();
	draw_left_bottom();
}

void draw_nine(void) {
	draw_top();
	draw_middle();
	draw_bottom();
	draw_left_top();
	draw_right_top();
	draw_right_bottom();
}

void draw_zero(void) {
	draw_top();
	draw_bottom();
	draw_right_top();
	draw_right_bottom();
	draw_left_top();
	draw_left_bottom();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s >> num;
	for (auto n : num)
	{
		switch (n)
		{
			case '1':
				draw_one();
				break ;
			case '2':
				draw_two();
				break ;
			case '3':
				draw_three();
				break ;
			case '4':
				draw_four();
				break ;
			case '5':
				draw_five();
				break ;
			case '6':
				draw_six();
				break ;
			case '7':
				draw_seven();
				break ;
			case '8':
				draw_eight();
				break ;
			case '9':
				draw_nine();
				break ;
			case '0':
				draw_zero();
				break ;
		}
		c += 2 + s + 1;
		r = 0;
	}
	for (int r = 0; r < 2*s + 3; r++)
	{
		for (int c = 0; c < (2 + s + 1) * num.length() - 1; c++)
		{
			if (print[r][c] == 0)
				cout << " ";
			else if (print[r][c] == 1)
				cout << "|";
			else if (print[r][c] == 2)
				cout << "-";
		}
		cout << "\n";
	}
}