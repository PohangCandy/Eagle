// DP����
// ������ ������ �ϱ�����, �޸� ����
// ���� ������ �ذ��ϱ� ���� ���� ������ ����
#include <iostream>
using namespace std;

int arr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// ������ �� N�� 1�� ����� ���� ������ �ּ� Ƚ����
	// 3���� ǥ������ ��Ÿ�� �� �ִ�.
	// arr[N] = arr[N-1] + 1;
	// arr[N] = arr[N/2] + 1;
	// arr[N] = arr[N/3] + 1;

	//0,1,2,3�� ���� ���� �ּ� Ƚ���� ���� ����־�д�.
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	
	int N;
	cin >> N;
	//4���� �Է����� �־����� N������ ������ ���� �ּڰ��� ���Ѵ�.
	for (int i = 4; i <= N; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
	}

	cout << arr[N];

	return 0;
}