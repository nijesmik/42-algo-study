#include <iostream>
#include <algorithm>
using namespace std;
int N, M, answer;
int map[501][501];

void Input()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
}

void FindMaxValueForFigureOne()
{
	int max_value;
	
	for (int i = 0; i < N; i++) // ㅡ
	{
		for (int j = 0; j+3 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
			answer = max(answer, max_value);
		}
	}
	
	for (int i = 0; i+3 < N; i++) // ㅣ
	{
		for (int j = 0; j < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
			answer = max(answer, max_value);
		}
	}
}

void FindMaxValueForFigureTwo()
{
	int max_value;
	
	for (int i = 0; i+1 < N; i++) // ㅁ
	{
		for (int j = 0; j+1 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1];
			answer = max(answer, max_value);
		}
	}
}

void FindMaxValueForFigureThree()
{
	int max_value;
	
	for (int i = 0; i+2 < N; i++) // 기본
	{
		for (int j = 0; j+1 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j+1];
			answer = max(answer, max_value);
		}
	}
	
	for (int i = 0; i+1 < N; i++) // 반시계 회전
	{
		for (int j = 2; j < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i+1][j] + map[i+1][j-1] + map[i+1][j-2];
			answer = max(answer, max_value);
		}
	}

	for (int i = 0; i+2 < N; i++) // 또 반시계 회전
	{
		for (int j = 0; j+1 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
			answer = max(answer, max_value);
		}
	}

	for (int i = 0; i+1 < N; i++) // 또 반시계 회전
	{
		for (int j = 0; j+2 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j];
			answer = max(answer, max_value);
		}
	}

	for (int i = 0; i+2 < N; i++) // 기본의 대칭
	{
		for (int j = 1; j < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j-1];
			answer = max(answer, max_value);
		}
	}

	for (int i = 0; i+1 < N; i++) // 반시계 회전
	{
		for (int j = 0; j+2 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
			answer = max(answer, max_value);
		}
	}

	for (int i = 0; i+2 < N; i++) // 또 반시계 회전
	{
		for (int j = 0; j+1 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i][j+1] + map[i+1][j] + map[i+2][j];
			answer = max(answer, max_value);
		}
	}

	for (int i = 0; i+1 < N; i++) // 또 반시계 회전
	{
		for (int j = 0; j+2 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2];
			answer = max(answer, max_value);
		}
	}
}

void FindMaxValueForFigureFour()
{
	int max_value;
	
	for (int i = 0; i+2 < N; i++) // 기본형
	{
		for (int j = 0; j+1 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1];
			answer = max(answer, max_value);
		}
	}

	for (int i = 1; i < N; i++) // 반시계 회전
	{
		for (int j = 0; j+2 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i][j+1] + map[i-1][j+1] + map[i-1][j+2];
			answer = max(answer, max_value);
		}
	}

	for (int i = 0; i+2 < N; i++) // 기본의 대칭
	{
		for (int j = 1; j < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i+1][j] + map[i+1][j-1] + map[i+2][j-1];
			answer = max(answer, max_value);
		}
	}

	for (int i = 0; i+1 < N; i++) // 반시계 회전
	{
		for (int j = 0; j+2 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+1][j+2];
			answer = max(answer, max_value);
		}
	}
}

void FindMaxValueForFigureFive()
{
	int max_value;
	
	for (int i = 0; i+2 < N; i++) // ㅏ
	{
		for (int j = 0; j+1 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
			answer = max(answer, max_value);
		}
	}

	for (int i = 0; i+2 < N; i++) // ㅓ
	{
		for (int j = 1; j < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i+1][j] + map[i+1][j-1] + map[i+2][j];
			answer = max(answer, max_value);
		}
	}

	for (int i = 1; i < N; i++) // ㅗ
	{
		for (int j = 0; j+2 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i][j+1] + map[i][j+2] + map[i-1][j+1];
			answer = max(answer, max_value);
		}
	}

	for (int i = 0; i+1 < N; i++) // ㅜ
	{
		for (int j = 0; j+2 < M; j++)
		{
			max_value = 0;
			max_value = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
			answer = max(answer, max_value);
		}
	}
}

void Solution()
{
	FindMaxValueForFigureOne();
	FindMaxValueForFigureTwo();
	FindMaxValueForFigureThree();
	FindMaxValueForFigureFour();
	FindMaxValueForFigureFive();

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
