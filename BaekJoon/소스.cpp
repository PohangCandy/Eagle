// 입력받은 string 객체가 
// 공백문자를 제외하고 
// 거꾸러 만들어져야 한다.
// getline함수로 문장을 입력받은 후에, 
// 해당 객체를 공백 문자가 나오기 전까지 stack에 담고
// 공백 문자가 나오면 stack에 있는 값을 
// 모두 꺼내서 다른 스택에 저장한다.

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<char> stk;

	int T;
	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; i++)
	{
		string input;
		getline(cin, input);
		for(auto &a: input)
		{
			// 공백을 기준으로 할 경우 
			// 마지막 단어를 출력시키지 못한다.
			if (a == ' ')
			{
				while (!stk.empty())
				{
					cout << stk.top();
					stk.pop();
				}
				cout << " ";
			}
			else
			{
				stk.push(a);
			}
		}

		while (!stk.empty())
		{
			cout << stk.top();
			stk.pop();
		}
		cout << "\n";
	}


		
	return 0;
}