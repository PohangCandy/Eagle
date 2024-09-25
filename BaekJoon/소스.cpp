// �ǿ����ڸ� ���ÿ� �ְ�, 
// �����ڸ� ���� ���
// ���ÿ� �ִ� �� ���� ������ �������ش�.
#include <iostream>
#include <stack>
using namespace std;

//���ĺ��� ���� ���� ������� �迭�� ������ش�.
double alpha[27];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	string str;
	cin >> str;

	stack<double> stk;

	for (int i = 0; i < N; i++)
	{
		double input;
		cin >> input;
		//���ĺ��� ����� ���� �迭�� ����
		alpha[i] = input;
	}

	for (int i = 0; i < str.length(); i++)
	{
		// �տ������� ������� �˻��ϸ鼭
		// �ǿ����ڸ� ���ÿ� �ִ´�.
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			stk.push(alpha[str[i] - 'A']);
		}
		else
		{
		// �����ڸ� ������ ���ÿ� �ִ� 
		// �� ���� ���� ������ ��������.
			if (!stk.empty())
			{
				double a = stk.top();
				stk.pop();
				double result = 0;
				if (str[i] == '+')
				{
					result = stk.top() + a;
				}
				else if (str[i] == '-')
				{
					result = stk.top() - a;
				}
				else if (str[i] == '/')
				{
					result = stk.top() / a;
				}
				else if (str[i] == '*')
				{
					result = stk.top() * a;
				}
				stk.pop();
				// ������ ����� �ٽ� stk�� �ִ´�.
				stk.push(result);
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << stk.top();

	return 0;
}