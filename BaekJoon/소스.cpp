#include <iostream>
using namespace std;
// 우리가 최대 100000개라
// 들어갈 수 있는 최대 사자는 총 50000마리이다.
// 배열을 arr[100001][50001]이면 크다고 오류난다.

// 2 * n 개의 우리에서
// n번째 행에 사자가 들어있거나, 한마리만 들어있는 경우를 배열로 나타낸다.
// 사자가 첫번째 우리에 없는 경우 [n][0]
// 사자 한마리가 첫번째 우리 왼쪽에 있는 경우 [n][1]
// 사자 한마리가 첫번째 우리 오른쪽에 있는 경우 [n][2]

int arr[100001][3];

int RR(int arr[][3], int n)
{
	arr[1][0] = 1;
	arr[1][1] = 1;
	arr[1][2] = 1;
	for (int i = 2; i <= n; i++)
	{
		//i번째 행에 사자가 없는 경우의 수는
		//i-1번째 행에 사자가 없거나
		//i-1번째 행에 사자가 왼쪽에 있거나
		//i-1번째 행에 사자가 오른쪽에 있는 경우의 수의 총합이다.
		arr[i][0] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % 9901;
		arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % 9901;
		arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % 9901;
	}

	return (arr[n][0] + arr[n][1] + arr[n][2]) % 9901;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	cout << RR(arr, N);

	return 0;
}