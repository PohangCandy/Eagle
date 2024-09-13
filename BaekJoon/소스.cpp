//���ڿ�, �������� ��ȣ�� �߰��� ���ԵǾ� �ִ� ��쿡�� �� ���� �� �̷�� �ִ����� ����Ѵ�.
#include <iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<char> stk;

	// �Է��� ���� ���� (,),[,]�� �������� Ȯ���ߴٰ�
	// ���࿡ ������ �ݴ��� ���� �ִ��� Ȯ���ظ� ���� ������?
	// ������ �̿��ؼ� �����Ѵ�.
	string s;

	while (1)
	{
		while (!stk.empty())
		{
			stk.pop();
		}
		getline(cin, s);
		if (s == ".") break;
		auto a = s.begin();
		while (a != s.end())
		{
			if (*a == '(' || *a == '[')
			{
				stk.push(*a);
			}
			else if (*a == ')')
			{
				if (!stk.empty())
				{
					if (stk.top() == '(') stk.pop();
					else break;
				}
				else //empty����� ���� �������� �˷��ֱ� ����
				{
					stk.push(*a);
					break;
				}	
			}
			else if (*a == ']')
			{
				if (!stk.empty())
				{
					if (stk.top() == '[') stk.pop();
					else break;
				}
				else //empty����� ���� �������� �˷��ֱ� ����
				{
					stk.push(*a);
					break;
				}
			}
			a++;
		}
		if (stk.empty()) cout << "yes" <<"\n";
		else cout << "no" << "\n";
	}


	return 0;
}
