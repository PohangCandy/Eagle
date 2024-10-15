#include <iostream>
using namespace std;

//�� ��ĥ�ϱ�
// RGB������ ĥ�ϴµ� �ּڰ��� �ǵ����Ѵ�.
// ���� �Է� ���� ����, ����
// [0][1][2]�� ��� �迭�� �����.
// 
// ���� �ִ� ģ���� ���� �޶���Ѵ�.
// �ι�° ������ R�϶� ù��° ������ ���� �ּҰ� �Ǵ� ���� ��Ÿ����.
//���������� ��¦ Ʋ�� ���� ������?
// ó�� �����ϴ� ���� ������ �����ϴ� ������ ����� ����
// �ʷ�, �Ķ��̾���Ѵ�.
// �ʷ�, �Ķ����� ���� ��� ������ �ʷ�, �Ķ��̸� �ȵȴ�.
// ó���� �������� ���������� ������ش�.
// �ʷ�,�Ķ��� ���� ����� �ִ����� �ǵ��� �����.
// ���� �ִ� ����� 1000,���� ������ 1000�̹Ƿ�
//�ִ� ���� �� �ִ� ����� 1000*1000�̴�.


int arr[1001][3];
int price[1001][3];

void RR(int arr[][3], int price[][3], int n);

int setting(int arr[][3],int price[][3],int n)
{
	int minimum = 1000 * 1000;

	for (int firstColor = 0; firstColor <= 2; firstColor++)
	{
		for (int i = 0; i <= 2; i++)
		{
			if (i == firstColor)
			{
				price[1][firstColor] = arr[1][firstColor];
			}
			else
			{
				price[1][i] = 1000 * 1000;
			}
		}

		RR(arr, price, n);

		for (int i = 0; i <= 2; i++)
		{
			if (i == firstColor)
			{
				continue;
			}
			else
			{
				minimum = min(minimum, price[n][i]);
			}
		}
	}

	return minimum;
}

void RR(int arr[][3], int price[][3], int n)
{

	for (int i = 2; i <= n; i++)
	{
		price[i][0] = arr[i][0] + min(price[i - 1][1], price[i - 1][2]);
		price[i][1] = arr[i][1] + min(price[i - 1][0], price[i - 1][2]);
		price[i][2] = arr[i][2] + min(price[i - 1][0], price[i - 1][1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int input;
			cin >> input;
			arr[i][j] = input;
		}
	}

	cout << setting(arr,price, N);

	return 0;
}