// �Է¹��� string ��ü�� 
// ���鹮�ڸ� �����ϰ� 
// �Ųٷ� ��������� �Ѵ�.
// getline�Լ��� ������ �Է¹��� �Ŀ�, 
// �ش� ��ü�� ���� ���ڰ� ������ ������ stack�� ���
// ���� ���ڰ� ������ stack�� �ִ� ���� 
// ��� ������ �ٸ� ���ÿ� �����Ѵ�.

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<char> stk;

	int T;
	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; i++)
	{
		string input;
		getline(cin, input);
		for(auto &a: input)
		{
			// ������ �������� �� ��� 
			// ������ �ܾ ��½�Ű�� ���Ѵ�.
			if (a == ' ')
			{
				while (!stk.empty())
				{
					cout << stk.top();
					stk.pop();
				}
				cout << " ";
			}
			else
			{
				stk.push(a);
			}
		}

		while (!stk.empty())
		{
			cout << stk.top();
			stk.pop();
		}
		cout << "\n";
	}


		
	return 0;
}