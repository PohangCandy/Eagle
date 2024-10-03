#include <iostream>
using namespace std;

long long RR(long long(*arr)[4], int n)
{
// 1	1
// 2	2
// 3	1 2	, 2 1 , 3
// 4	1 3	, 1 2 1 , 3 1
// 5	1 3 1 , 2 1 2, 2 3 , 3 2
// 5를 표현하는 방법
// 1로 시작 + 4을 표현하는 방법 중 1로 시작하는 순서 제외
// 2로 시작 + 3을 표현하는 방법 중 2로 시작하는 순서 제외
// 3으로 시작 + 2를 표현하는 방법 중 3로 시작하는 순서 제외
	// n >= 4인 경우
	// [n][1] = [n-1][2] + [n-1][3]
	// [n][2] = [n-2][1] + [n-2][3]
	// [n][3] = [n-3][1] + [n-3][2]

	arr[0][0] = 0;
	arr[0][1] = 0;
	arr[0][2] = 0;
	arr[0][3] = 0;

	arr[1][0] = 1;
	arr[1][1] = 1;
	arr[1][2] = 0;
	arr[1][3] = 0;

	arr[2][0] = 1;
	arr[2][1] = 0;
	arr[2][2] = 1;
	arr[2][3] = 0;

	arr[3][0] = 3;
	arr[3][1] = 1;
	arr[3][2] = 1;
	arr[3][3] = 1;

	for(int i = 4; i <= n; i++)
	{
		arr[i][1] = (arr[i - 1][2] + arr[i - 1][3]) % 1000000009;
		arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % 1000000009;
		arr[i][3] = (arr[i - 3][1] + arr[i - 3][2]) % 1000000009;
	}

		//n을 1,2,3으로 나타낸 경우의 수의 총 합
	return (arr[n][1] + arr[n][2] + arr[n][3]) % 1000000009;

	//for (int i = 4; i <= n; i++)
	//{
	//	arr[i][1] = (arr[i - 1][0] - arr[i - 1][1]) % 1000000009;
	//	arr[i][2] = (arr[i - 2][0] - arr[i - 2][2]) % 1000000009;
	//	arr[i][3] = (arr[i - 3][0] - arr[i - 3][3]) % 1000000009;
	//	arr[i][0] = (arr[i][1] + arr[i][2] + arr[i][3]) % 1000000009;
	//}

	////n을 1,2,3으로 나타낸 경우의 수의 총 합
	//return arr[n][0];
}

long long arr[100000][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int input;
		cin >> input;
		cout << RR(arr, input) << "\n";
	}

	return 0;
}