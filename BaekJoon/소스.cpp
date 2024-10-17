#include <iostream>
#include <algorithm>
using namespace std;

//애니팡

/*
힌 줄 바꿔서, 가장 긴 사탕이 있는 줄 출력하기
사탕을 배열에 담은 뒤에, 뒤에 있거나 아래에 있는 경우, count를 증가시킨다.
max가 되는 count 값을 저장시킨다.

먼저 사탕을 최대로 넣을 수 있는 배열을 만든다.
입력한 입력 값만큼, 가로 배열과 세로 배열의 값을 증가시킨다.

색상 4개에 대한 배열을 따로 만든다.

i,j번째 요소에서
가로와 세로 줄을 계속 세면되지 않을까?
가로로 증가시키면서 최대 몇개가 연속될 수 있는지
조사하고
세로로 증가시키면서 최대 몇개가 될 수 있는지
조사해본다.

80%에서 멈춘다.
반례가 발생하고 있기때문에
예외가 있는지 모든 사항을 고려해본다.

예외적인 경우가 있다.

p p p c p p p p
z y z z y z y z
위와 같은 경우 
p p p이후에 오는 c,p를 교환하는 경우
p p p (p c) p p p 로 교체하면 앞 줄은 p가 4개, 뒷 줄은 3개가 된다.
p p (c p) p p p p 로 교체하면 앞 줄은 p가 3개, 뒷 줄은 5개가 된다.

가로를 검사할때
for(int i  = 0 ; i < N; i++)
for(int j = 0 ; i < N ; j++)
for(int k = j+1; k < N; k++)
[i][j]번째 요소와 [i][k]번째 요소를 비교했을때

[i][j] == [i][k]라면, 연속된 수를 저장하는 배열에 담아준다.
arr[0] ++;
arr[1]++, 체인지를 한번 선언한 경우의 뱌열도 똑같이 증가한다.

[i][j] != [i][k]리면,
자리 체인지를 통해 연속될 수 있는지 먼저 알아본다.

1. 상,하 체인지로 연속되는 경우 
[i][j] == [i+1][k] || [i][j] == [i-1][k]
arr[1] = arr[0] + 1; 지금까지 연속된 합 + 체인지를 통해 더해진 1
연속된 수를 저장하는 배열은 초기화
arr[0] = 0 ;

2. 좌, 우 체인지로 연속되는 경우
[i][j] == [i][k+1] == [i][k-1]인 경우
k = 1일때
P C P 같은 경우를 말한다.

*/

char anipang[51][51];

//이미 한 번 바꿨을 경우와, 한 번도 안 바꿨을 경우를 고려해준다.
int arr[2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			char c;
			cin >> c;
			anipang[i][j] = c;
		}
	}

	int M = 1;

	//가로에 대해서 먼저 조사

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[0] = 1;
			arr[1] = 1;
			char basicWord = anipang[i][j];
			for (int k = j + 1; k <= N; k++)
			{
				if (basicWord == anipang[i][k])
				{
					arr[0]++;
					arr[1]++; 
				}
				else if (basicWord == anipang[i + 1][k] || basicWord == anipang[i - 1][k])
				{
					arr[1] = arr[0] + 1;
					arr[0] = 0;
				}
				else if (k + 1 < N && basicWord == anipang[i][k+2] && anipang[i][k-1] == anipang[i][k + 1])
				{
					arr[1] = arr[0] + 1;
					M = max({ M,arr[0], arr[1]});
					arr[1] = 1;
					arr[0] = 0;
				}
				else
				{
					//p p p c p p p p
					//c c p c c p
					arr[1] = 0;
					arr[0] = 0;
				}
				M = max({M,arr[0], arr[1]});
			}
		}
	}

	//세로에 대한 조사
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[0] = 1;
			arr[1] = 1;
			char basicWord = anipang[j][i];
			for (int k = j + 1; k <= N; k++)
			{
				if (basicWord == anipang[k][i])
				{
					arr[0]++;
					arr[1]++;
				}
				else if (basicWord == anipang[k][i+1] || basicWord == anipang[k][i-1])
				{
					arr[1] = arr[0] + 1;
					arr[0] = 0;
				}
				else if (k + 1 < N && basicWord == anipang[k + 1][i])
				{
					arr[1] = arr[0] + 1;
					M = max({ M,arr[0], arr[1] });
					arr[1] = 1;
					arr[0] = 0;
				}
				else
				{
					arr[1] = 0;
					arr[0] = 0;
				}

				M = max({ M,arr[0], arr[1] });
			}
		}
	}

	cout << M;


	return 0;
}