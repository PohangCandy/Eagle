//stack에 2개의 숫자가 쌓이면
//top을 그냥 더하고
//pop한 후에
//그 다음 top을 *100을 해서 더한다.
#include <stack>
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<int> stk;

	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int input;
		cin >> input;
		stk.push(input);
		if (stk.size() >= 2)
		{
			result += stk.top();
			stk.pop();
			//
			result += stk.top() * 100;
			stk.pop();
		}
	}

	cout << result;

	return 0;
}