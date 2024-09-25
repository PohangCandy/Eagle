// 수식에 쓰이는 수의 순서는 변화가 없다.
// 입력이 스택의 top보다 우선순위가 낮을 경우 전체 연산자를 pop한다.
// 입력이 스택의 top보다 우선순위가 높거나 같을 경우 스택에 push
// 같은 부호일때 push를 해주었더니 답이 2개가 나온다.
// A+B*C-D/E*F+G
// 동일부호 push 허용: ABC*+DEF*/-G+
// 기대값: ABC*+DE/F*-G+

//현재 문제에서 ()를 기준으로 설명하고 있으므로
//사칙연산답게 동일 부호일 경우 앞서 나온 부호의 우선순위를 더 먼저 쳐준다.

#include <iostream>
#include <stack>
using namespace std;

bool IsInputBigOrSamethanTop(char input, char top)
{
	// +,-는 우선순위 최하위
	// top이 ( 라면 true가 된다.
	if (input == '+' || input == '-')
	{
		if (top == '(')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (input == '*' || input == '/')
	{
		if (top == '*' || top == '/')
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	// (는 항상 우선 순위이다.
	else if (input == '(')
	{
		return true;
	}
	else
	{
		cout << "wrong operator" << "\n";
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;

	stack<char> stk;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			//피연산자 순서는 바뀌지 않는다.
			//피연산자라면 그대로 출력
			cout << input[i];
		}
		else
		{
			if (!stk.empty())
			{
				// 입력이 )경우만 특별히 적용해준다.
				if (input[i] == ')')
				{
					//(가 나오기까지 스택에 남아있는 모든 연산자를 pop해준다.
					while (!(stk.top() == '('))
					{
						cout << stk.top();
						stk.pop();
					}
					//(연산자도 빼준다.
					stk.pop();
				}
				//입력이 스택의 top보다 우선순위가 높거나 같을 경우 스택에 push
				else if (IsInputBigOrSamethanTop(input[i], stk.top()))
				{
					stk.push(input[i]);
				}
				//입력이 스택의 top보다 우선순위가 낮을 경우
				else
				{
					// 스택에 (가 있다면 
					// (를 뺀 값들을 모두 출력하고
					// 아니라면
					// 스택의 모든 연산자를 출력한다.
					// 이때 스택을 pop하면서 입력과 top의 우선순위를 계속 비교해주어야한다.
					while ((!stk.empty()) && !(stk.top() == '(') && !(IsInputBigOrSamethanTop(input[i], stk.top())))
					{
						cout << stk.top();
						stk.pop();
					}
					// 이후 스택에 입력 연산자를 넣어준다.
					stk.push(input[i]);

				}
			}
			else
			{
				stk.push(input[i]);
			}
		}
	}

	//마지막에 스택에 남아있는 연산자들은 털어준다.
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}