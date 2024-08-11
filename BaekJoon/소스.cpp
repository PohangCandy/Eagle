#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int M, N;
	int BWcount = 0;
	int WBcount = 0;

	cin >> M >> N;
	vector<vector<char>> Map;
	vector<char> line;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char input;
			cin >> input;
			line.push_back(input);
		}
		Map.push_back(line);
	} 

	for (int i = 0; i < M - 8; i++)
	{
		for (int j = 0; j < N - 8; j++)
		{
			for(int k = )
		}
	}
	//BW와 비교하기
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i % 2 == 0)//짝수 줄인 경우
			{
				if (j % 2 == 0)//짝수 번째 단어인 경우
				{
					if (Map[i][j] == 'B')
					{
						BWcount++;
					}
				}
				else if (j % 2 == 1)//홀수 번째 단어인 경우
				{
					if (Map[i][j] == 'W')
					{
						BWcount++;
					}
				}
			}
			else if (i % 2 == 1)//홀수 줄인 경우
			{
				if (j % 2 == 0)//짝수 번째 단어인 경우
				{
					if (Map[i][j] == 'W')
					{
						BWcount++;
					}
				}
				else if (j % 2 == 1)//홀수 번째 단어인 경우
				{
					if (Map[i][j] == 'B')
					{
						BWcount++;
					}
				}
			}
		}
	}
	//WB와 비교하기
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i % 2 == 0)//짝수 줄인 경우
			{
				if (j % 2 == 0)//짝수 번째 단어인 경우
				{
					if (Map[i][j] == 'W')
					{
						BWcount++;
					}
				}
				else if (j % 2 == 1)//홀수 번째 단어인 경우
				{
					if (Map[i][j] == 'B')
					{
						BWcount++;
					}
				}
			}
			else if (i % 2 == 1)//홀수 줄인 경우
			{
				if (j % 2 == 0)//짝수 번째 단어인 경우
				{
					if (Map[i][j] == 'B')
					{
						BWcount++;
					}
				}
				else if (j % 2 == 1)//홀수 번째 단어인 경우
				{
					if (Map[i][j] == 'W')
					{
						BWcount++;
					}
				}
			}
		}
	}

	if (BWcount > WBcount)
	{
		cout << M * N - BWcount;
	}
	else 
	{
		cout << M * N - WBcount;
	}

	



	return 0;
}