// ���Ŀ� ���̴� ���� ������ ��ȭ�� ����.
// �Է��� ������ top���� �켱������ ���� ��� ��ü �����ڸ� pop�Ѵ�.
// �Է��� ������ top���� �켱������ ���ų� ���� ��� ���ÿ� push
// ���� ��ȣ�϶� push�� ���־����� ���� 2���� ���´�.
// A+B*C-D/E*F+G
// ���Ϻ�ȣ push ���: ABC*+DEF*/-G+
// ��밪: ABC*+DE/F*-G+

//���� �������� ()�� �������� �����ϰ� �����Ƿ�
//��Ģ������ ���� ��ȣ�� ��� �ռ� ���� ��ȣ�� �켱������ �� ���� ���ش�.

#include <iostream>
#include <stack>
using namespace std;

bool IsInputBigOrSamethanTop(char input, char top)
{
	// +,-�� �켱���� ������
	// top�� ( ��� true�� �ȴ�.
	if (input == '+' || input == '-')
	{
		if (top == '(')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (input == '*' || input == '/')
	{
		if (top == '*' || top == '/')
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	// (�� �׻� �켱 �����̴�.
	else if (input == '(')
	{
		return true;
	}
	else
	{
		cout << "wrong operator" << "\n";
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;

	stack<char> stk;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			//�ǿ����� ������ �ٲ��� �ʴ´�.
			//�ǿ����ڶ�� �״�� ���
			cout << input[i];
		}
		else
		{
			if (!stk.empty())
			{
				// �Է��� )��츸 Ư���� �������ش�.
				if (input[i] == ')')
				{
					//(�� ��������� ���ÿ� �����ִ� ��� �����ڸ� pop���ش�.
					while (!(stk.top() == '('))
					{
						cout << stk.top();
						stk.pop();
					}
					//(�����ڵ� ���ش�.
					stk.pop();
				}
				//�Է��� ������ top���� �켱������ ���ų� ���� ��� ���ÿ� push
				else if (IsInputBigOrSamethanTop(input[i], stk.top()))
				{
					stk.push(input[i]);
				}
				//�Է��� ������ top���� �켱������ ���� ���
				else
				{
					// ���ÿ� (�� �ִٸ� 
					// (�� �� ������ ��� ����ϰ�
					// �ƴ϶��
					// ������ ��� �����ڸ� ����Ѵ�.
					// �̶� ������ pop�ϸ鼭 �Է°� top�� �켱������ ��� �����־���Ѵ�.
					while ((!stk.empty()) && !(stk.top() == '(') && !(IsInputBigOrSamethanTop(input[i], stk.top())))
					{
						cout << stk.top();
						stk.pop();
					}
					// ���� ���ÿ� �Է� �����ڸ� �־��ش�.
					stk.push(input[i]);

				}
			}
			else
			{
				stk.push(input[i]);
			}
		}
	}

	//�������� ���ÿ� �����ִ� �����ڵ��� �о��ش�.
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}