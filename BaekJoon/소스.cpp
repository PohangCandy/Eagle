#include <iostream>
using namespace std;


//char input[5][15]; //5�ܾ�,�ִ� ���� 15

int main()
{

	char input[5][15] = {0}; //5�ܾ�,�ִ� ���� 15, ���� ������ ��� ���� 0���� �ʱ�ȭ ���־�� �Ѵ�.
	//5�ܾ �޴´�.
	for (int i = 0; i < 5; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (input[j][i] != NULL)
			{
				cout << input[j][i];
			}
		}
	}


	return 0;
}

