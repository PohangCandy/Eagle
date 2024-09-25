#include <iostream>
#include <stack>
using namespace std;

stack<char> oper;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// �켱������ �� ���� ��ȣ�� �����Ǹ� 
	// ���� pop�ϰ�
	// �� ������ �״�� ���ÿ� ��´�.
	// (�� ������
	// �� ������ ���� ��ȣ�� ������ ���ÿ� ���
	// )�� ������ 
	// (�� ���ö����� ���� pop�Ѵ�.
	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		//�Է��� �ܾ��� �׳� ����Ѵ�.
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			cout << input[i];
		}
		//�Է��� �����ڶ��
		else
		{
			//�ٸ� �����ڰ� ���ÿ� �̹� �ִٸ�
			if (!oper.empty())
			{
				char c = input[i];
				char t = oper.top();
				if (c == '*' || c == '/')
				{
					oper.push(c);
				}
				else if (c == '+' || c == '-')
				{
					//
					if (t == '(')
					{

					}
					else if (t == '*' || t == '/')
					{
						while (!oper.empty())
						{
							cout << oper.top();
							oper.pop();
						}
					}
				}
				else if (c == '(')
				{
					oper.push(c);
				}
				else if (c == ')')
				{

				}
			}
			//�ٸ� �����ڰ� ���ÿ� ���ٸ�
			else
			{
				oper.push(input[i]);
			}

		}
	}


	return 0;
}