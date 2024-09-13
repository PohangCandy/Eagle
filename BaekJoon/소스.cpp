//문자열, 여러가지 괄호가 중간에 포함되어 있는 경우에도 한 쌍을 잘 이루고 있는지를 출력한다.
#include <iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	stack<char> stk;

	// 입력을 받을 동안 (,),[,]가 들어오는지 확인했다가
	// 만약에 들어오면 반대편 쌍이 있는지 확인해면 되지 않을까?
	// 스택을 이용해서 구현한다.
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
				else //empty결과를 통해 오답임을 알려주기 위함
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
				else //empty결과를 통해 오답임을 알려주기 위함
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
