// �־��� ���� ���̰� 1,000,000�̶� �ǹ̴�
// 2^1,000,000���� ǥ���� �� �ִٴ� ���� ����.
// �� ���� (2^10)^100000�̹Ƿ� �뷫 10^300000�� �ȴ�.
// longlong�̳� int������ ǥ���� �� ���� �����̹Ƿ�
// string�� ����ؼ� �Է��� �޵����Ѵ�.

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;

	//8�������� �ٲٷ��� �տ������� ���ڸ��� ���� �ٲٸ� �ȴ�.
	//input % 3�� Ȯ���ϰ�, 0�� ������ ������� �տ� 0�� �־
	//�������� 0�� �ǵ��� �����.
	while (input.size() % 3 != 0)
	{
		input = '0' + input;
	}
	//���� 3�ڸ��� 8�������� �о��ش�. 
	for (int i = 0; i < input.size(); i += 3)
	{
		cout << (input[i] - '0') * 4 + (input[i + 1] - '0') * 2 + (input[i + 2] - '0') * 1;
	}

	return 0;
}