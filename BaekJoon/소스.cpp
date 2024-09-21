// 입력된 수와 스택이 top이 다르다면 
// push하며 +를 출력하다 
// 수열에 해당하는 수와 스택의 top이 일치하면
// pop하고 -를 출력한다.
// push는 항상 오름차순으로 받으므로,
// 입력한 값이 스택의 top보다 작다면
// pop할 수 없으므로
// No를 출력한다.


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