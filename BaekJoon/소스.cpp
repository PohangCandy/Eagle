// nCm
// n! / r! * (n-r)!
// 각각에서 2와 5가 얼마나 있는지 알아낸다.
// 분모에 있는 2와 5의 개수를 분자가 갋아먹게 만든다.
// 배열을 선언해서 분모의 2와 5의 개수를 담고
// 분자의 2와 5의 개수만큼 빼준다.

#include <iostream>
using namespace std;

void CountTwoFive(long long&two, long long&five, int n)
{
	//i가 2*10^9 * 2가 되어 int형 최대치를 초과할 수 있다.
	for (long long i = 2; i <= n; i *= 2)
	{
		two += n / i;
	}
	for (long long i = 5; i <= n; i *= 5)
	{
		five += n / i;
	}
}

void SubtractTwoFive(long long& two, long long& five, int n)
{
	for (long long i = 2; i <= n; i *= 2)
	{
		two -= n / i;
	}
	for (long long i = 5; i <= n; i *= 5)
	{
		five -= n / i;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//빈 배열로 초기화
	//2와 5의 개수가 int형을 초과 할 수 있다.
	long long store[2] = { 0 };

	int n, m;
	cin >> n >> m;

	//일일히 순회하면서 n! 값 안에 있는 2와 5의 개수를 찾으면
	//시간초과에 걸린다.
	//최대 2,000,000,000 이 들어가므로 O(n)번 순회하면 이미 20초다
	//2의 배수를 찾는 방법을 에라토스체를 통해서 떠올려본다.
	//2의 배수는 2,4,6,8,10...이다.
	//N!에 해당 값들이 있다고 가정하고 2로 나눠본다.
	//2 * (1,2,3,4,5,6...)라는 결과가 된다.
	//여기서 4,8,16과 같은 2의 제곱수에서 한번더 2를 추출할 수 있다.
	//즉 2의 개수를 찾기위해서
	// n/2 + n/4 + ... until n >= 2^x 까지 시행하면 될 것이다.
	// n뿐만 아니라 m, n-m에 대해서도 시행하기위해 함수 형태로 만들어본다.
	CountTwoFive(store[0], store[1], n);
	SubtractTwoFive(store[0], store[1], m);
	SubtractTwoFive(store[0], store[1], n-m);

	//2와 5중에서 더 적은 값을 출력해준다.
	cout << min(store[0], store[1]);
	return 0;
}