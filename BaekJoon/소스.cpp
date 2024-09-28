#include <iostream>
using namespace std;

//������ ���� ������ ��ŷ �ð��ʰ��� �߻��Ѵ�.
//���丮�� ������ ���� �ִ°ǰ�?
//N! = 1 * 2 * 3 * ... * N
//2�� 5�� ��� ���� �󸶳� �ִ��� ã�ƺ���?

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long N;
	cin >> N;
	long long pac = 1;
	long long count_two = 0;
	long long count_five = 0;
	for (long long i = 1; i <= N; i++)
	{
		int j = i;
		while (j % 2 == 0)
		{
			count_two++;
			j /= 2;
		}

		while(j % 5 == 0)
		{
			count_five++;
			j /= 5;
		}
	}

	//�� �߿� �� ���� ���� ������ �ȴ�.
	if (count_two >= count_five)
	{
		cout << count_five;
	}
	else
	{
		cout << count_two;
	}

	return 0;
}