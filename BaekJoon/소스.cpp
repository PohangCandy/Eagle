#include <iostream>
#include <vector>
using namespace std;
// 1 1
// 2 1,1
// 3 1,1,1
// 4 4
// 5 4,1
// 6 4,1,1
// 7 4,1,1,1
// 8 4,4
// 9 9
// 10 9 1
// 11 9 1 1
// 12 9 1 1 1
// 12 4 4 4
// 12에 가장 가까운 제곱수는 9이지만 최소 항을 가지는 수열이 아니다.
// 12보다 적은 제곱수 중에 제곱수를 뺀 나머지에서
// 최소항을 가지도록 만드는 수를 찾아야한다.



int RR(int arr[], int input)
{
	arr[0] = 0;
	arr[1] = 1;
// 항을 최대한 많이 가질경우 
// 1로 나눈 몫과 같다. 
	arr[input] = input;

//입력받은 수보다 작거나 같은 수들에 대한 최소항을 구해서 저장한다.
	for (int i = 2; i <= input; i++)
	{
		int min = i;
		//완전제곱수인 경우 최소항은 1
		//그외에는 제곱수와 나머지를 이루는 수의 최소항의 개수를 비교해서
		//그 중 최솟값을 저장한다.
		for (int j = 1; j * j <= i; j++)
		{
			if (j * j == i)
			{
				min = 1;
			}
			else if (min > (arr[j * j] + arr[i - (j * j)]))
			{
				min = (arr[j * j] + arr[i - (j * j)]);
			}
		}
		arr[i] = min;
	}

	return arr[input];
	 
}

// 각 수에 대한 최소 항을 기억하도록 하는 배열
int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	cout << RR(arr, N);


	return 0;
}