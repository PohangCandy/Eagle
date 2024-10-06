#include <iostream>
#include <vector>
using namespace std;
// 1 1
// 2 1,1
// 3 1,1,1
// 4 4
// 5 4,1
// 6 4,1,1
// 7 4,1,1,1
// 8 4,4
// 9 9
// 10 9 1
// 11 9 1 1
// 12 9 1 1 1
// 12 4 4 4
// 12�� ���� ����� �������� 9������ �ּ� ���� ������ ������ �ƴϴ�.
// 12���� ���� ������ �߿� �������� �� ����������
// �ּ����� �������� ����� ���� ã�ƾ��Ѵ�.



int RR(int arr[], int input)
{
	arr[0] = 0;
	arr[1] = 1;
// ���� �ִ��� ���� ������� 
// 1�� ���� ��� ����. 
	arr[input] = input;

//�Է¹��� ������ �۰ų� ���� ���鿡 ���� �ּ����� ���ؼ� �����Ѵ�.
	for (int i = 2; i <= input; i++)
	{
		int min = i;
		//������������ ��� �ּ����� 1
		//�׿ܿ��� �������� �������� �̷�� ���� �ּ����� ������ ���ؼ�
		//�� �� �ּڰ��� �����Ѵ�.
		for (int j = 1; j * j <= i; j++)
		{
			if (j * j == i)
			{
				min = 1;
			}
			else if (min > (arr[j * j] + arr[i - (j * j)]))
			{
				min = (arr[j * j] + arr[i - (j * j)]);
			}
		}
		arr[i] = min;
	}

	return arr[input];
	 
}

// �� ���� ���� �ּ� ���� ����ϵ��� �ϴ� �迭
int arr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	cout << RR(arr, N);


	return 0;
}