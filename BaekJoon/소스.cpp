// �� ���� �Է� �޾Ƽ� �ּҰ������ �������.
// �ϳ��� ���� ����� ���� ��, �ٸ� ���� ������ �������� 0�̸� ������� �ȴ�.
// �� ū ���� ã�Ƽ� �ش� ���� ����� ���� ���� ������ �۾��� �� ȿ�����̴�.

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int first, second;
		int common_mutiple;

		cin >> first >> second;
		if (first >= second)
		{
			int i = 1;
			while (1)
			{
				int first_copy = first * i;
				if (first_copy % second == 0)
				{
					common_mutiple = first_copy;
					break;
				}
				i++;
			}
			cout << common_mutiple << "\n";
		}
		else
		{
			int i = 1;
			while (1)
			{
				int second_copy = second * i;
				if (second_copy % first == 0)
				{
					common_mutiple = second_copy;
					break;
				}
				i++;
			}
			cout << common_mutiple << "\n";
		}

	}

	return 0;
}