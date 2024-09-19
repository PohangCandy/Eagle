#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<int> stk;

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		if (input == "push")
		{
			int x;
			cin >> x;
			stk.push(x);
		}
		else if (input == "pop")
		{
			if (!stk.empty())
			{
				cout << stk.top() << "\n";
				stk.pop();
			}
			else cout << -1 << "\n";
		}
		else if (input == "size")
		{
			cout << stk.size() << "\n";
		}
		else if (input == "empty")
		{
			if (stk.empty())
			{
				cout << 1 << "\n";
			}
			else cout << 0 << "\n";
		}
		else if (input == "top")
		{
			if (stk.empty())
			{
				cout << -1 << "\n";
			}
			else cout << stk.top() << "\n";
		}
	}

	return 0;
}