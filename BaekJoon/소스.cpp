#include <iostream>
using namespace std;

// 점화식, recurrence relation
int RR(int n)
{
	int arr[1001];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
	}

	return arr[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//	1개 짜리 채우는 경우의 수는 1
	//	2개 짜리 채우는 경우의 수는 3
	//	3개 짜리 채우는 경우의 수는 5
	//	4개 짜리 채우는 경우의 수는 11
	//  그림을 그려 규칙을 찾는다.
	//	점화식은 f(n) = f(n-1) + f(n-2) * 2

	int n;
	cin >> n;
	
	cout << RR(n);

	return 0;
}