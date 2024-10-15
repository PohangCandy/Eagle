#include <iostream>
using namespace std;

//집 색칠하기
// RGB색으로 칠하는데 최솟값이 되도록한다.
// 먼저 입력 받은 값을, 각각
// [0][1][2]에 담는 배열을 만든다.
// 
// 옆에 있는 친구랑 색이 달라야한다.
// 두번째 집부터 R일때 첫번째 집과의 합이 최소가 되는 집을 나타낸다.
//마지막에만 살짝 틀면 되지 않을까?
// 처음 시작하는 빨간 색으로 시작하는 끝나는 경우의 수는
// 초록, 파랑이어야한다.
// 초록, 파랑으로 끝날 경우 시작이 초록, 파랑이면 안된다.
// 처음을 빨강으로 강제적으로 만들어준다.
// 초록,파랑색 집의 비용을 최대비용이 되도록 만든다.
// 집의 최대 비용이 1000,집의 개수가 1000이므로
//최대 나올 수 있는 비용은 1000*1000이다.


int arr[1001][3];
int price[1001][3];

void RR(int arr[][3], int price[][3], int n);

int setting(int arr[][3],int price[][3],int n)
{
	int minimum = 1000 * 1000;

	for (int firstColor = 0; firstColor <= 2; firstColor++)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (i == firstColor)
			{
				price[1][firstColor] = arr[1][firstColor];
			}
			else
			{
				price[1][i] = 1000 * 1000;
			}
		}

		RR(arr, price, n);

		for (int i = 0; i <= 2; i++)
		{
			if (i == firstColor)
			{
				continue;
			}
			else
			{
				minimum = min(minimum, price[n][i]);
			}
		}
	}

	return minimum;
}

void RR(int arr[][3], int price[][3], int n)
{

	for (int i = 2; i <= n; i++)
	{
		price[i][0] = arr[i][0] + min(price[i - 1][1], price[i - 1][2]);
		price[i][1] = arr[i][1] + min(price[i - 1][0], price[i - 1][2]);
		price[i][2] = arr[i][2] + min(price[i - 1][0], price[i - 1][1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int input;
			cin >> input;
			arr[i][j] = input;
		}
	}

	cout << setting(arr,price, N);

	return 0;
}