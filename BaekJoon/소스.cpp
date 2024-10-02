// DP문제
// 성능을 빠르게 하기위해, 메모리 낭비
// 상위 문제를 해결하기 위해 하위 문제로 분해
#include <iostream>
using namespace std;

int arr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 임의의 수 N을 1로 만들기 위한 연산의 최소 횟수는
	// 3가지 표현으로 나타낼 수 있다.
	// arr[N] = arr[N-1] + 1;
	// arr[N] = arr[N/2] + 1;
	// arr[N] = arr[N/3] + 1;

	//0,1,2,3에 대한 연산 최소 횟수를 먼저 집어넣어둔다.
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	
	int N;
	cin >> N;
	//4부터 입력으로 주어지는 N까지의 정수의 연산 최솟값을 구한다.
	for (int i = 4; i <= N; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
	}

	cout << arr[N];

	return 0;
}