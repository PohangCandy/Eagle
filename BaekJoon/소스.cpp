#include <iostream>
#include <vector>
using namespace std;

//존나 큰 바둑판이 있다.
//바둑판을 오려서 8*8크기의 바둑판만 추출한다.
//바둑판이 랜던하게 칠해져있기때문에
//검,흰 순서대로 칠했을 때 
//가장 적게 변화시킬 수 있는 위치를 찾아보고
//변화시킬 수를 출력한다.

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

//우선 존나 큰 바둑판에서 8 * 8 짜리 판을 추출하는 방법을 생각해본다.
//반복문을 쓰면 간단할 것이다.
//입력받은 M * N 짜리 판의 각 위치를 찾는다.
//처음 시작은 좌상단
//종점은 우하단에서 위로 8번째 좌로 8번째에 위치한 점이 되야한다.

	cout << "\n";
	cout << line.size();
	cout << Map.size();
	cout << "\n";

	
	int x, y;
	vector <vector<char>> minimap;
	vector <char> miniLine;
	for (int i = 0; i <= M - 8; i++) // 8번째 줄까지
	{
		for (int j = 0; j <= N - 8; j++) // 8번째 칸까지 
		{
			y = i;
			x = j;
			// 위치로부터 8*8짜리 맵을 추출한다.
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
			// BW와 비교하기
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (i % 2 == 0)// 짝수 줄인 경우
					{
						if (j % 2 == 0)// 짝수 번째 단어인 경우
						{
							if (minimap[i][j] == 'B')
							{
								BWcount++;
							}
						}
						else if (j % 2 == 1)// 홀수 번째 단어인 경우
						{
							if (minimap[i][j] == 'W')
							{
								BWcount++;
							}
						}
					}
					else if (i % 2 == 1)// 홀수 줄인 경우
					{
						if (j % 2 == 0)// 짝수 번째 단어인 경우
						{
							if (minimap[i][j] == 'W')
							{
								BWcount++;
							}
						}
						else if (j % 2 == 1)// 홀수 번째 단어인 경우
						{
							if (minimap[i][j] == 'B')
							{
								BWcount++;
							}
						}
					}
				}
			}
			// WB와 비교하기
			int WBcount = 0;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (i % 2 == 0)// 짝수 줄인 경우
					{
						if (j % 2 == 0)// 짝수 번째 단어인 경우
						{
							if (minimap[i][j] == 'W')
							{
								WBcount++;
							}
						}
						else if (j % 2 == 1)// 홀수 번째 단어인 경우
						{
							if (minimap[i][j] == 'B')
							{
								WBcount++;
							}
						}
					}
					else if (i % 2 == 1)// 홀수 줄인 경우
					{
						if (j % 2 == 0)// 짝수 번째 단어인 경우
						{
							if (minimap[i][j] == 'B')
							{
								WBcount++;
							}
						}
						else if (j % 2 == 1)// 홀수 번째 단어인 경우
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