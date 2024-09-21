// �Էµ� ���� ������ top�� �ٸ��ٸ� 
// push�ϸ� +�� ����ϴ� 
// ������ �ش��ϴ� ���� ������ top�� ��ġ�ϸ�
// pop�ϰ� -�� ����Ѵ�.
// push�� �׻� ������������ �����Ƿ�,
// �Է��� ���� ������ top���� �۴ٸ�
// pop�� �� �����Ƿ�
// No�� ����Ѵ�.


#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int> stk;
	int index = 1;
	vector<string> result;
	
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (stk.empty())
		{
			while (index <= n)
			{
				stk.push(index);
				result.push_back("+");
				if (stk.top() == input)
				{
					stk.pop();
					result.push_back("-");
					index++;
					break;
				}
				index++;
			}
		}
		else
		{
			if (stk.top() == input)
			{
				stk.pop();
				result.push_back("-");
			}
			else if(stk.top() < input)
			{
				while (index <= n)
				{
					stk.push(index);
					result.push_back("+");
					if (stk.top() == input)
					{
						stk.pop();
						result.push_back("-");
						index++;
						break;
					}
					index++;
				}
			}
			else
			{
				result.clear();
				stk.push(0);
			}
		}
	}


	if (stk.empty())
	{
		for (auto& a : result)
		{
			cout << a << "\n";
		}
	}
	else
	{
		cout << "NO";
	}
	
	return 0;
}