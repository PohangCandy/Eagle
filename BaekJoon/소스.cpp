#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// arr[i]		10 -4 3 1 5 6 -35 12 21 -1
	// dp[i][0]		10 
	// dp[i][1]		10 

	//dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
	//dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
	//MAX = max(MAX, max(dp[i][0], dp[i][1]));
	// 
	//dp[1][0] = max(6, -4);
	//dp[1][1] = max(10, 6);




	return 0;
}