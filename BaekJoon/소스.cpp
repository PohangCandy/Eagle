#include <iostream>
using namespace std;

// ��ȭ��, recurrence relation
int RR(int n)
{
	int arr[1001];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
	}

	return arr[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//	1�� ¥�� ä��� ����� ���� 1
	//	2�� ¥�� ä��� ����� ���� 3
	//	3�� ¥�� ä��� ����� ���� 5
	//	4�� ¥�� ä��� ����� ���� 11
	//  �׸��� �׷� ��Ģ�� ã�´�.
	//	��ȭ���� f(n) = f(n-1) + f(n-2) * 2

	int n;
	cin >> n;
	
	cout << RR(n);

	return 0;
}