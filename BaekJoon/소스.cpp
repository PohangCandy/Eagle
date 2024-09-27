//�����佺�׳׽��� ü�� ���⼭�� Ȱ��ȴ�.
//�Ҽ� ���� ������ �� Ȱ��Ǵ� ��
#include <iostream>
#include <algorithm>
using namespace std;

void IsPrimeNum(bool arr[], int size)
{
	//0�� 1�� �Ҽ��� �ƴϴ�.
	arr[0] = false;
	arr[1] = false;
	/*25�� �Ҽ����� �Ǵ��ϱ� ���ؼ� 5������ �����ϸ� �ǵ���
	25���� ���� ���� ��������� �ص� ����� 5���� ���� ���� ���� ���̴�.
	�׷��Ƿ� 25���� ���� �� �� 5���� ���� ���� ����� �ƴ϶�� �Ҽ��� �ȴ�.*/
	
	// �׷��Ƿ� ��� size���� ���� �Ҽ��� ã�� �۾���
	// size�� �����ٱ����� �����ϸ� �ȴ�.
	// ������� false�� ������ش�.
	for (int i = 0; i * i < size; i++)
	{
		//�̹� �ٸ� ���� ������ �Ѿ��.
		if (arr[i] == false) continue;
		else
		{
			// i�� ������� ã���ش�.
			// i * 2 , i * 3�� �̹� 2,3�� ����� ó���Ǿ��� ������
			//i * i���� ã������.
			for (int j = i * i; j < size; j += i)
			{
				arr[j] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	bool *che = new bool[1000001];
	//�޸� ���� ��� ���� �Ҽ��� �ʱ�ȭ
	fill(che, che + 1000001, true);
	IsPrimeNum(che, 1000001);
	bool find;
	int MaxTextSize = 1000000;
	while (MaxTextSize > 0)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		find = false;
		//�ε��� ���� �Ҽ��϶� true�� �迭����
		//���� n�� ¦�� ã�´�.
		//�ε��� ��ȣ�� n/2������ ã����ȴ�.
		//Ȧ���� �Ҽ� ������ ã���Ƿ�
		//Ȧ���� �ε��� ��ȣ�� �����Ѵ�.

		for (int i = 3; i <= n / 2; i += 2)
		{
			// �� ���� �Ҽ��̸� break�ϰ� ����Ѵ�.
			if (che[i] && che[n - i])
			{
				find = true;
				cout << n << " = " << i << " + " << n - i << "\n";
				break;
			}
		}

		if (!find)
		{
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
		
		MaxTextSize--;
	}

	delete[] che;
	return 0;
}