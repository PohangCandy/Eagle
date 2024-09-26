//stack�� 2���� ���ڰ� ���̸�
//top�� �׳� ���ϰ�
//pop�� �Ŀ�
//�� ���� top�� *100�� �ؼ� ���Ѵ�.
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