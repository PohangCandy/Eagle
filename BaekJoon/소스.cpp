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
	//BW�� ���ϱ�
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i % 2 == 0)//¦�� ���� ���
			{
				if (j % 2 == 0)//¦�� ��° �ܾ��� ���
				{
					if (Map[i][j] == 'B')
					{
						BWcount++;
					}
				}
				else if (j % 2 == 1)//Ȧ�� ��° �ܾ��� ���
				{
					if (Map[i][j] == 'W')
					{
						BWcount++;
					}
				}
			}
			else if (i % 2 == 1)//Ȧ�� ���� ���
			{
				if (j % 2 == 0)//¦�� ��° �ܾ��� ���
				{
					if (Map[i][j] == 'W')
					{
						BWcount++;
					}
				}
				else if (j % 2 == 1)//Ȧ�� ��° �ܾ��� ���
				{
					if (Map[i][j] == 'B')
					{
						BWcount++;
					}
				}
			}
		}
	}
	//WB�� ���ϱ�
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i % 2 == 0)//¦�� ���� ���
			{
				if (j % 2 == 0)//¦�� ��° �ܾ��� ���
				{
					if (Map[i][j] == 'W')
					{
						BWcount++;
					}
				}
				else if (j % 2 == 1)//Ȧ�� ��° �ܾ��� ���
				{
					if (Map[i][j] == 'B')
					{
						BWcount++;
					}
				}
			}
			else if (i % 2 == 1)//Ȧ�� ���� ���
			{
				if (j % 2 == 0)//¦�� ��° �ܾ��� ���
				{
					if (Map[i][j] == 'B')
					{
						BWcount++;
					}
				}
				else if (j % 2 == 1)//Ȧ�� ��° �ܾ��� ���
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