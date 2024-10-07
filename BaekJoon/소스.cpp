#include <iostream>
using namespace std;
// 배열[찾고 싶은 수][표현에 사용될 정수의 개수]
// 1을 정수 2개로 나타내는 방법
// [1][2]
// 0으로 시작하는 경우
// 0 + [1][1]
// 1로 시작하는 경우
// 1 + [0][1]
// 
// 2를 정수 1개로 나타내는 방법
// 2[1] = 1
// 2를 정수 2개로 나타내는 방법
// 2[2] = 0 + 2[1], 1 + 1[1], 2 + 0[1]
// ...
// 2를 정수 2개로 나타내는 방법
// 2[3] = 0 + 2[2], 1 + 1[2], 2 + 0[2]

// 각각의 숫자 N이 정수 K개로 나눠질 때
// 가지는 경우의 수에 대해 미리 저장하고 있는다.

// 문제의 핵심은 0이 표현되는 방법이다.
// [0][200] = 1 이다.
// 0을 200자리로 나타낼 때 0+0+...+0으로 0을 200번 더한다.

// 1[200]은 
// 1이 먼저 오는 1+0+0+...+0의 경우와 
// 0이 먼저 올 경우 0 + 1 + 0 ...+ 0이므로 1의 위치가 계속 바뀔 수 있다.
// 그러므로 0 + [1][199]의 경우의 수와 같다.

long long arr[201][201];

long long RR(long long arr[][201], int input, int num)
{
	for (int i = 0; i <= 200; i++)
	{
		arr[0][i] = 1;
	}

	for (int i = 1; i <= input; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			if (j == 1)
			{
				arr[i][j] = 1;
				//cout << "arr" << "[" << i << "]" << "[" << j << "]" << " = " << 1 << "\n";
				continue;
			}

			int total = 0;
			int back = j - 1;
			for (int k = i; k >= 0; k--)
			{
				total += arr[k][back];
				total %= 1000000000;
			}
			arr[i][j] = (total % 1000000000);
			//cout << "arr" << "[" << i << "]" << "[" << j << "]" << " = " << total << "\n";
		}
	}
	
	return (arr[input][num] % 1000000000);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	cout << RR(arr, N , K);

	return 0;
}