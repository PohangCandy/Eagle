#include <iostream>
using namespace std;

// nCm
// nPm / m!
// n!/(n - r)! * r!

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//2 * 10^9�̹Ƿ� �ƽ��ƽ��ϰ� int���� �� �� ����.
	//������ m * n�� 10^18�̵ȴ�.
	// longlong�� ���ش�.
	//int���� 4.2 * 10^9�� ������ �˰��ִ�.
	int n, m;
	cin >> n >> m;

	int a = n - m;
	int total = 0;
	//m�� 10^9�� ��� 20�ʰ� �����Եȴ�.
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

	// �����佺�׳׽��� ü�� �����ϸ� ���?
	// 2,4,6,8,10...�� 2�� ����� +1
	// 4,8,12,... �� 2�� ����� + 1
	// 8,16,24 ... �� ������ +1
	// 16,32,64... �ǹ���� +1
	// �̷������� �ؼ� 2^n < 2,000,000���� int�� �迭�� ���� ���Ѵٸ�
	// 4�ް�����Ʈ * 2 * 10^3 = 8GB���Ǽ� �뷮�ʰ��� �ȴ�..

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