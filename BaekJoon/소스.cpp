// â�����ݱⰡ ����Ǹ鼭 �ڽ��� ����� ������ ���� �����ȴ�.
// 1�� ��� ���� ����̹Ƿ� ��� â���� ���� ä�� �����ϰ�
// ����� ������ Ȧ�� ���� ���� ���������� 1�� �ȴ�.
// ����� ������ Ȧ�� ���� ���� ���� �������̴�.
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//�������� ���� �������� ������ ã���� �ȴ�.
	int N;
	cin >> N;

	int count = 0;
	for (int i = 1; i * i <= N; i++)
	{
		count++;
	}
	cout << count;

	return 0;
}