#include <iostream>
using namespace std;

// �����ϴٰ� �����ϴ� ������� ������ ���Ѵ�.
// 1 2 3 4 2 1
// �� �ε����� �ڽ��� ���������� �����ϴ� ������ üũ�ؾ��Ѵ�.
// ���� ���̶��
//  �ڽź��� ���� ���� �������� ������ �����ְ�
//	���ų� ū ���� ������ ������ �ߴܵȴ�.
// ���� ���̶�� 
//  �ڽź��� ū ���� ������ �� ������ �����ش�.
//
// �׷� 2���� ������ ���� totla���� �����ϸ� ���?
// ���� ���� �����ϴ� ����� total���� total_increase���ϰ�
// ���� ���� �����ϴ� ����� total���� total_decrease��� �Ѵ�.
// total_increase�� total_decrease�� ���� ���� ū ���� ����Ѵ�.


//�ð��ʰ�
// �������� 10^3^2 = 10^6 , 0.01��
//�޸�
// int,pair<int,int> 1000�� = 12kb
//�ڷ���
// �ִ� ���� 1000 <= int�ڷ��� (2 * 10^9)

int arr[1001];
//increase,decrease
pair<int, int> total[1001];

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
		total[i] = { 0,0 };
		for (int j = 1; j < i; j++)

			//�̷��� �� �ִ� ������Ż ����
			// ū �� ��
			// 20 19 18 10
			// �� �� ū
			// 10 18 19 20
			// �� ū ��
			// 8 9 10 9


		{
			//  5
			//  5 2
			//  5 2 4
			//  5 2 4
			//  5 2 4 2
			//  5(0,1) 2(max(���ʿ� 2���� ū ���� ���� 1,���ʿ� 2���� ���� ���� ����),max(�����ʿ� 2���� )) 4(1,1) 1(0,0) 5(2,0)
			// 10 6 7
			// 100() 6 70() 80 90

			if (arr[j] > arr[i])
			{
				total[j].second++;
				if (total[j].second > total[i].second)
				{
					total[i].second = total[j].second;
				}
			}
			else if (arr[j] < arr[i])
			{
				total[i].first = total[j].first;
				if (total[j].first > total[i].first)
				{
					total[i].first = total[j].first;
				}
			}
		}

	}

	//increase,decrease���� ��� �ڽ��� ���Խ��Ѽ� �������Ƿ� �ߺ��Ǵ� 1�� ���ش�.
	int maxBitonic = total[0].first + total[0].second - 1;

	for (int i = 1; i < N; i++)
	{
		int t = total[i].first + total[i].second - 1;
		if (t > maxBitonic)
		{
			maxBitonic = t;
		}
	}

	cout << maxBitonic;

	return 0;
}