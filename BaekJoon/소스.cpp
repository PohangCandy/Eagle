#include <iostream>
using namespace std;
// ������ ������ ������ ä�� ���� �� �κм����� ���̸� ���ؾ��Ѵ�.
// {10,1,2,3,4,5,20}���� ���� �� �κ� ������ 5�� ���;ߵȴ�.
// {10,1,2,3,11,12,13,14}���� ���� �� �κ� ������ 5�� ���;ߵȴ�.
// ���࿡ ���� �κм����� �߰� ���� ��ġ�� ���
// {10,1,2,20,21,22,23}
// �߰� ���� �տ��� � ������ �� ���� ��Ҹ� ������ �ֳĿ� �޷��ִ�.
// {7,8,9,10,1,2,3,4,5,10}
// input�� ������ 1�� ���
// 1 ~ (input - 1)�� ������ �ִ� ���� ���Ͽ�
// ���� ū ���� ��´�.
// arr[input] = 1;
// for(int i = 1; i <= input - 1; i++
// {
//	  if(arr[i] > arr[input]) arr[input] = arr[i];
// }
// 1000���� ���� 1000�� �־����ٸ�
// 10^6�̹Ƿ� 1�� �̸����� ����ȴ�.

void RR(int arr[], int N)
{
	arr[N] = 1;
	for (int i = 1; i <= (N - 1); i++)
	{
		if (arr[i] >= arr[N]) arr[N] = arr[i] + 1;
	}
}

int arr[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		RR(arr, input);
	}

	int max = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	cout << max;

	return 0;
}