#include <iostream>
#include <algorithm>
using namespace std;
// 수는 제외하거나, 제외하지 않을 경우가 있다.
// 수는 한번만 제외할 수 있으므로
// 해당 수를 제외할 경우, 지금까지 제외하지 않을 경우의 최댓값을 더해주어야한다.

int arr[100000];
// 수를 제외하는 경우와 수를 제외하지 않을 경우에 
// 연속의 최댓값을 저장할 배열을 선언해둔다.
int dp[100000][2];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
	}

	dp[0][0] = arr[0];
	dp[0][1] = arr[0];
	//어느 요소에서든
	//최댓값이 나오는 수열이 최댓값이 되므로
	//해당 값을 저장해준다.
	int Max = arr[0];

	for (int i = 1; i < n; i++)
	{
		//지금 요소와 이전 요소의 총합을 비교한다.
		// 이전 요소의 총합이 음수라면
		//더할 필요없이 지금 수열에서 새로운 수열로 시작한다.
		// -5 -7 2는 2부터 수열을 시작해야한다.
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		//-를 제외하는 경우는 2가지이다.
		//현재값을 제외하지 않는 경우 = 지금까지 -를 한번 사용했을 경우 + 현재값
		//현재값을 제외할 경우 = 지금까지 -없이 더한 총합
		dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i-1][0]);
		
		Max = max({ Max,dp[i][0],dp[i][1] });

	}

	cout << Max;

	return 0;
}