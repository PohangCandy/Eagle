// �ܾ� ������
// <>�� �ִ� ģ������ �״�� ������
// �������� �ݴ�� ������ �����Ƿ�
// deq�� ����ؼ�
// <�� �����Ǹ�
// >�� ���ö����� ���� �״�� pop�Ѵ�.
// ���鹮���� ���,
// deq�� ����������� pop_back �Ѵ�.
// �Ϲݹ����� ��� push_front �Ѵ�.

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	deque<char> deq;

	string input;
	getline(cin, input);
	// ���鹮�ڸ� �������� �ܾ ������ ���̹Ƿ�
	// ���Ƿ� ���鹮�ڸ� �߰��Ѵ�.
	input += " ";
	bool p_f = false;

	for (auto& a : input)
	{
		if (a == ' ')
		{
			while (!deq.empty())
			{
				cout << deq.back();
				deq.pop_back();
			}
			cout << " ";
		}
		else if (a == '<')
		{
			p_f = true;
			deq.push_front(a);
		}
		else if (a == '>')
		{
			if (p_f)
			{
				deq.push_front(a);
				p_f = false;
				while (!deq.empty())
				{
					cout << deq.back();
					deq.pop_back();
				}
			}
			else
			{
				deq.push_back(a);
			}
		}
		else
		{
			if (p_f)
			{
				deq.push_front(a);
			}
			else
			{
				deq.push_back(a);
			}
		}
	}

	return 0;
}