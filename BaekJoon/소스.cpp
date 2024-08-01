#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	// i = 1 ~ n-2
	// n - 2번 반복
	// j = i + 1 ~ n-1
	// n - 1 - i번 반복( 2 <= j <= n - 1 )
	// k = j + 1 ~ n
	// n - (j + 1) + 1 = n - j번 반복( 3 <= k <= n )
	// 
	// ((n-2) + ... + 1) + ((n-3) + ... + 1) + ... + (1)
	// (n-1)(n-2) + (n - 2)(n - 3) + ... + 1 * 2 / 2 ??
	// 
	// (n - 2) * (n - 1 - i) * (n - j) ??
	// 
	// 1 * (n - 2) + 2 * (n - 3) + ... + (n - 3) * 2 + (n - 2) * 1
	// 
	// 
	long long sum = 0;
	for(int i = n - 2; i > 0; i--)
	{
		sum += i * ((n - 2) - (i - 1));
	}

	cout << sum  << "\n" << 3;

	return 0;
}