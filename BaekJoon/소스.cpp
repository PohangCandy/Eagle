//to_string�� ����ؼ� �� �� ������ �ڵ�� �ۼ��غ���.
#include <iostream>
#include <string>
using namespace std;

int remocon[10] = {0};

bool check(int n)
{
	//���� string���� ��ȯ�ؼ� 
	//�ڸ����� �ش��ϴ� ���� ���忩�θ� 
	//�ε����� ���� �����ϰ� üũ�Ѵ�.
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++)
	{
		//���峭 ��ư�� ��� 
		if (remocon[s[i] - '0'] == 1)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int broken;
	cin >> broken;
	for (int i = 0; i < broken; i++)
	{
		int input;
		cin >> input;
		remocon[input] = 1;
	}
	//���� �׳� ���Ʒ� ��ư�� �����̴� ��츦 ���Ѵ�.
	int result = abs(N - 100);

	// �ִ�� �Էµ� �� �ִ� ��찡 500000�̹Ƿ�
	// �������� ���峯 ��츦 ����� �ִ� 999999�� �Է¹��� �� �ִ�.
	// i �� 500000 �̰�  Ű���尡 9�� ������ ���
	for (int i = 0; i <= 999999; i++)
	{
		//i�� �ش��ϴ� ���� Ű���ٰ� ���峪�� �ʾҴ��� üũ�Ѵ�.
		if (!check(i))
		{
			continue;
		}

		//���� ��ư�� ��� ���峪�� �ʾ��� ���
		//�ش� ä�ο����� �Ÿ��� ���Ѵ�.
		string s = to_string(i);
		int count = abs(N - i) + s.length();
		result = min(result,count);
	}

	cout << result;

	return 0;
}