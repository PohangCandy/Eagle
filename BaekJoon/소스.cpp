#include <iostream>
#include <vector>
using namespace std;

//���� ū �ٵ����� �ִ�.
//�ٵ����� ������ 8*8ũ���� �ٵ��Ǹ� �����Ѵ�.
//�ٵ����� �����ϰ� ĥ�����ֱ⶧����
//��,�� ������� ĥ���� �� 
//���� ���� ��ȭ��ų �� �ִ� ��ġ�� ã�ƺ���
//��ȭ��ų ���� ����Ѵ�.

int main()
{
	ios_base::sync_with_stdio(false);

	int M, N;
	vector<vector<char>> Map;
	vector<char> line;

	int min = 64;

	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		line.clear();
		for (int j = 0; j < N; j++)
		{
			char input;
			cin >> input;
			line.push_back(input);
		}
		Map.push_back(line);
	}

//�켱 ���� ū �ٵ��ǿ��� 8 * 8 ¥�� ���� �����ϴ� ����� �����غ���.
//�ݺ����� ���� ������ ���̴�.
//�Է¹��� M * N ¥�� ���� �� ��ġ�� ã�´�.
//ó�� ������ �»��
//������ ���ϴܿ��� ���� 8��° �·� 8��°�� ��ġ�� ���� �Ǿ��Ѵ�.

	cout << "\n";
	cout << line.size();
	cout << Map.size();
	cout << "\n";

	
	int x, y;
	vector <vector<char>> minimap;
	vector <char> miniLine;
	for (int i = 0; i <= M - 8; i++) // 8��° �ٱ���
	{
		for (int j = 0; j <= N - 8; j++) // 8��° ĭ���� 
		{
			y = i;
			x = j;
			// ��ġ�κ��� 8*8¥�� ���� �����Ѵ�.
			for (i; i < y + 8; i++) // 0~7
			{
				miniLine.clear();
				for (j; j < x + 8; j++) // 0~7
				{
					miniLine.push_back(Map[i][j]);
				}
				minimap.push_back(miniLine);
			}

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					cout << minimap[i][j];
				}
				cout << '\n';
			}

			int BWcount = 0;
			// BW�� ���ϱ�
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (i % 2 == 0)// ¦�� ���� ���
					{
						if (j % 2 == 0)// ¦�� ��° �ܾ��� ���
						{
							if (minimap[i][j] == 'B')
							{
								BWcount++;
							}
						}
						else if (j % 2 == 1)// Ȧ�� ��° �ܾ��� ���
						{
							if (minimap[i][j] == 'W')
							{
								BWcount++;
							}
						}
					}
					else if (i % 2 == 1)// Ȧ�� ���� ���
					{
						if (j % 2 == 0)// ¦�� ��° �ܾ��� ���
						{
							if (minimap[i][j] == 'W')
							{
								BWcount++;
							}
						}
						else if (j % 2 == 1)// Ȧ�� ��° �ܾ��� ���
						{
							if (minimap[i][j] == 'B')
							{
								BWcount++;
							}
						}
					}
				}
			}
			// WB�� ���ϱ�
			int WBcount = 0;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (i % 2 == 0)// ¦�� ���� ���
					{
						if (j % 2 == 0)// ¦�� ��° �ܾ��� ���
						{
							if (minimap[i][j] == 'W')
							{
								WBcount++;
							}
						}
						else if (j % 2 == 1)// Ȧ�� ��° �ܾ��� ���
						{
							if (minimap[i][j] == 'B')
							{
								WBcount++;
							}
						}
					}
					else if (i % 2 == 1)// Ȧ�� ���� ���
					{
						if (j % 2 == 0)// ¦�� ��° �ܾ��� ���
						{
							if (minimap[i][j] == 'B')
							{
								WBcount++;
							}
						}
						else if (j % 2 == 1)// Ȧ�� ��° �ܾ��� ���
						{
							if (minimap[i][j] == 'W')
							{
								WBcount++;
							}
						}
					}
				}
			}

			if (BWcount > WBcount)
			{
				if (min > 64 - BWcount)
					min = 64 - BWcount;
			}
			else
			{
				if (min > 64 - WBcount)
					min = 64 - WBcount;
			}
			j = x;
			i = y;
		}
	}

	
	cout << min;


	return 0;
}