#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//�ҹ���,�빮��,����,������ ������ ���� ����
	int result[5];

	string input;
	//�Է��� eof�� �ƴҰ�� ��� ����
	while (getline(cin, input))
	{
		//��� ���� 0���� �ʱ�ȭ
		for (int i = 0; i < 4; i++)
		{
			result[i] = 0;
		}

		for (auto& a : input)
		{
			if (a == ' ')
			{
				result[3]++;
			}
			else if (a >= 'A' && a <= 'Z')
			{
				result[1]++;
			}
			else if (a >= 'a' && a <= 'z')
			{
				result[0]++;
			}
			else
			{
				result[2]++;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			cout << result[i];
			if (i != 3) cout << " ";
		}
		cout << "\n";
	}


	return 0;
}