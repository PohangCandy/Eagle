#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	// ���μ����� 
	// 2���� �������� 0�� �Ǵ� ���� ã��
	// ���� ó���� �������� ������ ���� ��
	// �ٽ� 2���� �������� ���� ã�´�.
	// �ش� �۾��� �ݺ��� ��,
	// ���� 1�̵Ǹ� �ش� �۾��� �����.

	while (1)
	{
		for (int i = 2; i <= N; i++)
		{
			if (N % i == 0)
			{
				cout << i << "\n";
				N = N / i;
				break;
			}
		}
		if (N == 1)
			break;
	}



	return 0;
}