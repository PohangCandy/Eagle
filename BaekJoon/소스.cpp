#include <iostream>
using namespace std;

// nCm
// nPm / m!
// n!/(n - r)! * r!

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//2 * 10^9이므로 아슬아슬하게 int형이 될 것 같다.
	//하지만 m * n이 10^18이된다.
	// longlong을 써준다.
	//int형이 4.2 * 10^9인 것으로 알고있다.
	int n, m;
	cin >> n >> m;

	int a = n - m;
	int total = 0;
	//m이 10^9일 경우 20초가 지나게된다.
	if (a >= m)
	{
		int n_sum = 1;
		for (int i = 0; i < m; i++)
		{
			n_sum *= n;
			n--;
		}
		
		int m_sum = 1;
		for (int i = 0; i < m; i++)
		{
			m_sum *= m;
			m--;
		}

		total = n_sum / m_sum;
	}
	else
	{

	}

	// 에라토스테네스의 체를 응용하면 어떨까?
	// 2,4,6,8,10...의 2의 배수에 +1
	// 4,8,12,... 의 2의 배수에 + 1
	// 8,16,24 ... 의 베수에 +1
	// 16,32,64... 의배수에 +1
	// 이런식으로 해서 2^n < 2,000,000까지 int형 배열을 만들어서 구한다면
	// 4메가바이트 * 2 * 10^3 = 8GB가되서 용량초과가 된다..

	int q_first_with_two = 0;
	int q_second_with_two = 0;
	int q_first_with_five = 0;
	int q_second_with_five = 0;

	while (n % 5 == 0)
	{
		q_first_with_five++;
		n /= 5;
	}

	while (n % 2 == 0)
	{
		q_first_with_two++;
		n /= 2;
	}

	while (m % 5 == 0)
	{
		q_second_with_five++;
		m /= 5;
	}

	while (m % 2 == 0)
	{
		q_second_with_two++;
		m /= 2;
	}

	if (q_first_with_five - q_second_with_five >= q_first_with_two - q_second_with_two)
	{
		cout << q_first_with_two - q_second_with_two;
	}
	else
	{
		cout << q_first_with_five - q_second_with_five;
	}


	return 0;
}