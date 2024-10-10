#include <iostream>
using namespace std;
//���� �� �����ϴ� �κ� ������ ���̸� ���Ѵ�.
//�׳� �ڱ⺸�� ū ���� ������ count�� �������Ѽ�
//�ڽ��� �ε����� �ش��ϴ� �迭�� �����صθ� ���� ������?


//�ð�����
// �ִ� N�� 10^3�̹Ƿ� ���� �������� �ɸ� �� �ִ� �ִ� �ð�
// 10^6
//   
//�޸� 
// 4����Ʈ int�� 1000�� �����ϴ� �迭 2��, 8kb
//
//�ڷ���
//�ִ� ���� 1000 < 2*10^9�̹Ƿ� int������ �ۼ� 

int arr[1001];
int Count[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
		Count[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (arr[j] > arr[i])
			{
				if (Count[j] + 1 > Count[i])
				{
					Count[i] = Count[j] + 1;
				}
			}
		}
	}

	int maxCount = Count[1];
	for (int i = 1; i <= N; i++)
	{
		if (Count[i] > maxCount)
		{
			maxCount = Count[i];
		}
	}

	cout << maxCount;

	return 0;
}