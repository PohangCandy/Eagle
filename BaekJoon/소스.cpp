// �ǿ����ڸ� ���ÿ� �ְ�, 
// �����ڸ� ���� ���
// ���ÿ� �ִ� �� ���� ������ �������ش�.
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//���ĺ��� ���� ���� ������� �迭�� ������ش�.
	int alpha[27];

	int N;
	cin >> N;
	string str;
	cin >> str;

	stack<int> stk;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		//���ĺ��� ����� ���� �迭�� ����
		alpha[i] = input;
	}

	for (int i = 0; i < str.length(); i++)
	{
		// �տ������� ������� �˻��ϸ鼭
		// �ǿ����ڸ� ���ÿ� �ִ´�.
		// �����ڸ� ������ ���ÿ� �ִ� �� ���� ���� ������ ��������.

		
	}

	return 0;
}