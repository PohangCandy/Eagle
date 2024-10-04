#include <iostream>
using namespace std;
// 수열의 순서가 유지된 채로 가장 긴 부분수열의 길이를 구해야한다.
// {10,1,2,3,4,5,20}에서 가장 긴 부분 수열이 5가 나와야된다.
// {10,1,2,3,11,12,13,14}에서 가장 긴 부분 수열이 5가 나와야된다.
// 만약에 최장 부분수열의 중간 값이 겹치는 경우
// {10,1,2,20,21,22,23}
// 중간 값의 앞에서 어떤 수열이 더 많은 요소를 가지고 있냐에 달려있다.
// {7,8,9,10,1,2,3,4,5,10}
// input이 들어오면 1을 담고
// 1 ~ (input - 1)이 가지고 있는 값과 비교하여
// 가장 큰 값을 담는다.
// arr[input] = 1;
// for(int i = 1; i <= input - 1; i++
// {
//	  if(arr[i] > arr[input]) arr[input] = arr[i];
// }
// 1000개의 수와 1000이 주어진다면
// 10^6이므로 1초 미만으로 실행된다.

void RR(int arr[], int N)
{
	arr[N] = 1;
	for (int i = 1; i <= (N - 1); i++)
	{
		if (arr[i] >= arr[N]) arr[N] = arr[i] + 1;
	}
}

int arr[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		RR(arr, input);
	}

	int max = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	cout << max;

	return 0;
}