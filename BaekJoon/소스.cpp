// nCm
// n! / r! * (n-r)!
// �������� 2�� 5�� �󸶳� �ִ��� �˾Ƴ���.
// �и� �ִ� 2�� 5�� ������ ���ڰ� �E�Ƹ԰� �����.
// �迭�� �����ؼ� �и��� 2�� 5�� ������ ���
// ������ 2�� 5�� ������ŭ ���ش�.

#include <iostream>
using namespace std;

void CountTwoFive(long long&two, long long&five, int n)
{
	//i�� 2*10^9 * 2�� �Ǿ� int�� �ִ�ġ�� �ʰ��� �� �ִ�.
	for (long long i = 2; i <= n; i *= 2)
	{
		two += n / i;
	}
	for (long long i = 5; i <= n; i *= 5)
	{
		five += n / i;
	}
}

void SubtractTwoFive(long long& two, long long& five, int n)
{
	for (long long i = 2; i <= n; i *= 2)
	{
		two -= n / i;
	}
	for (long long i = 5; i <= n; i *= 5)
	{
		five -= n / i;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//�� �迭�� �ʱ�ȭ
	//2�� 5�� ������ int���� �ʰ� �� �� �ִ�.
	long long store[2] = { 0 };

	int n, m;
	cin >> n >> m;

	//������ ��ȸ�ϸ鼭 n! �� �ȿ� �ִ� 2�� 5�� ������ ã����
	//�ð��ʰ��� �ɸ���.
	//�ִ� 2,000,000,000 �� ���Ƿ� O(n)�� ��ȸ�ϸ� �̹� 20�ʴ�
	//2�� ����� ã�� ����� �����佺ü�� ���ؼ� ���÷�����.
	//2�� ����� 2,4,6,8,10...�̴�.
	//N!�� �ش� ������ �ִٰ� �����ϰ� 2�� ��������.
	//2 * (1,2,3,4,5,6...)��� ����� �ȴ�.
	//���⼭ 4,8,16�� ���� 2�� ���������� �ѹ��� 2�� ������ �� �ִ�.
	//�� 2�� ������ ã�����ؼ�
	// n/2 + n/4 + ... until n >= 2^x ���� �����ϸ� �� ���̴�.
	// n�Ӹ� �ƴ϶� m, n-m�� ���ؼ��� �����ϱ����� �Լ� ���·� ������.
	CountTwoFive(store[0], store[1], n);
	SubtractTwoFive(store[0], store[1], m);
	SubtractTwoFive(store[0], store[1], n-m);

	//2�� 5�߿��� �� ���� ���� ������ش�.
	cout << min(store[0], store[1]);
	return 0;
}