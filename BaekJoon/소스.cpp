#include <iostream>
using namespace std;
// 삼각형을 타도 내려가면서 최대합 구하기
// 과연 어떻게 왼쪽,오른쪽 삼각형을 타고 내려갈 수 있을까?
// 1번째로 입력받은 값은 2,3번째로 갈 수 있다.
// 1 -> 2,3
// 2 -> 4,5
// 3 -> 5,6
// 4 -> 7,8
// 5 -> 8,9
// 6 -> 9,10
//
//10 15
//8 1 5
//18 11 16 20

//삼각형을 이루는 총 항의 개수 = n*(n+1)/2
// 
//가장 마지막 항arr[n*(n+1)/2]에서
//삼각형의 윗 꼭지점에 접근하려면
//arr[n*(n+1)/2 - n] += max(arr[n*(n+1)/2],arr[n*(n+1)/2 - 1])
//이 작업을 각 줄의 두번째 항까지 반복한다.
//그 다음 윗 줄로 올라간다.
//최종적으로 arr[1]에 남은 값이 최댓값이 된다.

int arr[500 * 501 / 2 + 1];

int RR(int arr[], int n)
{
	for (n; n > 1; n--)
	{
		arr[n * (n + 1) / 2 - n] += max(arr[n * (n + 1) / 2], arr[n * (n + 1) / 2 - 1]);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		arr[i] = 0;
	}

	cout << RR(arr, n);

	return 0;
}