#include <iostream>
using namespace std;
// n = 1일때,
// 아무것도 고르지 않을 경우의 인덱스 0,
// 위쪽을 고르는 경우 인덱스 1,
// 아래쪽을 고르는 경우 인덱스 2라 한다.
// 아무것도 고르지 않았을 때, 가격의 최댓값
// arr[1][0] = 0;
// arr[1][1] = 50;
// arr[1][2] = 30;
// arr[2][0] = max(arr[1][1], arr[1][2])
// arr[2][1] += arr[1][2]
// arr[2][2] += arr[1][1]
// arr[3][0] = max(arr[2][1],arr[2][2])
// arr[3][1] += max(arr[2][2], arr[2][0])
// arr[3][2] += max(arr[2][1], arr[2][0])

// 점화식
// arr[n][0] = max(arr[n-1][1],arr[n-1][2])
// arr[n][1] += max(arr[n-1][2],arr[n-1][0])
// arr[n][2] += max(arr[n-1][1],arr[n-1][0])
// 
// n * 2개의 스티커에서 가겨이 최대가 되는 값
// return max(arr[n][1], arr[n][2])

int arr[100001][3];

int RR(int arr[][3], int n)
{
	arr[1][0] = 0;

	for (int i = 2; i <= n; i++)
	{
		//초기화
		arr[i][0] = 0;

		arr[i][0] = max(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] += max(arr[i - 1][2], arr[i - 1][0]);
		arr[i][2] += max(arr[i - 1][1], arr[i - 1][0]);
	}

	return max(arr[n][1], arr[n][2]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		//스티커 윗줄의 가격
		for (int i = 1; i <= n; i++)
		{
			int input;
			cin >> input;
			arr[i][1] = input;
		}
		//스티커 아랫줄의 가격
		for (int j = 1; j <= n; j++)
		{
			int input;
			cin >> input;
			arr[j][2] = input;
		}

		cout << RR(arr, n) << "\n";
	}


	return 0;
}