#include <iostream>
#include <stack>
using namespace std;

stack<char> oper;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// 우선순위가 더 낮은 부호가 감지되면 
	// 전부 pop하고
	// 더 높으면 그대로 스택에 담는다.
	// (가 나오면
	// 그 다음에 나온 부호는 무조건 스택엥 담고
	// )가 나오면 
	// (이 나올때까지 전부 pop한다.
	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		//입력이 단어라면 그냥 출력한다.
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			cout << input[i];
		}
		//입력이 연산자라면
		else
		{
			//다른 연산자가 스택에 이미 있다면
			if (!oper.empty())
			{
				char c = input[i];
				char t = oper.top();
				if (c == '*' || c == '/')
				{
					oper.push(c);
				}
				else if (c == '+' || c == '-')
				{
					//
					if (t == '(')
					{

					}
					else if (t == '*' || t == '/')
					{
						while (!oper.empty())
						{
							cout << oper.top();
							oper.pop();
						}
					}
				}
				else if (c == '(')
				{
					oper.push(c);
				}
				else if (c == ')')
				{

				}
			}
			//다른 연산자가 스택에 없다면
			else
			{
				oper.push(input[i]);
			}

		}
	}


	return 0;
}