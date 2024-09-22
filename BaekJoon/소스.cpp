#include <iostream>
#include <stack>
using namespace std;

// ������ ����ؼ� ������ �ذ��غ���.
// ���� �ϳ������� �߰��� �ִ� ��Ҹ� ���� �� �� �����Ƿ�
// �ΰ��� ����� Ŀ���� �߽����� �����ش�.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<char> left;
	stack<char> right;

	string input;
	cin >> input;
	for (auto& a : input)
	{
		left.push(a);
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		char c;
		cin >> c;
		if (c == 'L')
		{
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
		}
		else if (c == 'D')
		{
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
		}
		else if (c == 'B')
		{
			if (!left.empty())
			{
				left.pop();
			}
		}
		else if (c == 'P')
		{
			char p;
			cin >> p;
			left.push(p);
		}
	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}

	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}

	return 0;
}