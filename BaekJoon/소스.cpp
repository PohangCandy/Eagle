#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	//�ռ����� ������
	int N;
	int result = 0;
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		int num = i;

		while (num != 0)
		{
			sum += num % 10;
			num /= 10;
		}
		if (sum + i == N)
		{
			result = i;
			break;
		}
	}

	cout << result;

	return 0;
}