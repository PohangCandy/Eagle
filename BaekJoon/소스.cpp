#include<iostream>

#define endl "\n"
using namespace std;

int dp[100001][2], arr[100001];
int N;

void Answer()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dp[0][0] = arr[0];
	dp[0][1] = arr[0];
	// 가장 최대값이 될 수 있는 수를 담는다.
	int MAX = arr[0];
	for (int i = 1; i < N; i++)
	{
		// 음수를 제외하지 않았을때
		// 현재까지의 총합이 입력보다 작다면
		// 즉 , arr[i] > dp[i - 1][0] + arr[i]이라면
		// 이 경우 dp[i - 1][0] > 0이라는 의미이다.
		// dp[i - 1][0]을 폐기처분하고 arr[i]를 dp[i]에 담는다.
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		//음수를 제외할 경우
		//현재 입력으로 들어온 음수를 제거할 경우
		//dp[i - 1][0]을 dp[i][1]에 저장해주고,
		//이전에 음수를 이미 제외한 총합과 지금의 입력을 더하는 경우
		//dp[i-1][1] + arr[i]을 저장해준다.
		//즉, 현재 입력을 제외하는 경우와 이전에 입력을 제외한 경우를 비교해서
		//더 작은 음수가 제거되게 해준다.
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);

		MAX = max(MAX, max(dp[i][0], dp[i][1]));
	}
	cout << MAX;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Answer();
	return 0;
}