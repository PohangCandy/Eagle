#include <iostream>
#include <stack>
using namespace std;

// 스택을 사용해서 문제를 해결해본다.
// 스택 하나만으론 중간에 있는 요소를 삭제 할 수 없으므로
// 두개를 만들어 커서를 중심으로 나눠준다.

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