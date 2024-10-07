#include <iostream>
using namespace std;
//1을 1가지 수로 나타내는 방법
//1[1] = 1
//2를 1가지 수로 나타내는 방법
//2[1] = 1
//2를 2개로 나타내는 방법
//2[2] = 1, 1 + 1[1]
//...
//6을 4가지로 나타내려면
//6[4]
// 1 + 5[3] 
// -> 1 + 4[2]
// -> 2 + 3[2]
// -> 3 + 2[2]
// 2 + 4[3] 
// ->  1 + 3 [2] ->1,2   2,1
// ->  2 + 2 [2] ->1,1
// 2,1,1,2  2,1,2,1
// 2,2,1,1
// 3 + 3[3] ->  3,1,1,1

//각 수별로 몇 개로 나눠지는 지에 대한 정보를 미리 담고있어야 한다.
// 배열[각 수][나눠지는 종류]
// arr[51][20] -> 51을 20개의 정수로 표현한 가짓수


int arr[201][201];

int RR(int arr[][201], int input, int num)
{
	// 0 = 0
	arr[0][1] = 1;
	for (int i = 1; i <= input; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
			{
				arr[i][j] = 1;
				continue;
			}
			int total = 0;
			for (int k = i; k >= 0; k--)
			{
				total += arr[k][j - 1];
			}
			arr[i][j] = total;
			//arr[6][1] = 1
			//arr[6][2] = 0,arr[6][1] + 1,arr[5][1] + ... + 6,arr[0][1]
			//arr[6][3] = 0,arr[6][2] + 1,arr[5][2] + ... + 6,arr[0][2]
			//arr[i][j] = arr[i-j][j]
		}
	}
	

	return arr[input][num];
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