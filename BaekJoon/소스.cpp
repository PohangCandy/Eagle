// 학생들을 번호 순서대로 집어넣게 하기위한 프로그램
// 입력받은 번호가, 다음에 들어올 숫자면 제외(통과)하고
// 아니라면 스택에 쌓는다.
// 스택에 가장 최근에 들어온 값이 다음에 들어갈 숫자면 pop한다.

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	int order = 1;

	stack<int> line;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		//input을 입력받고 , order와 다르다면 stack에 있는 값들도 나가지 못한다.
		//input이 order라면, 라인을 통과시킨 후 다음 순서가 스택의 탑에 있는지 조사한다.
		if (input == order)
		{
			order++;
			while (!line.empty())
			{
				if (line.top() == order)
				{
					line.pop();
					order++;
				}
				else break;
			}
		}
		//input이 order가 아니면 stack에 넣는다.
		else 
		{
			line.push(input);
		}
	}

	if (!line.empty())
	{
		cout << "Sad";
	}
	else cout << "Nice";


	return 0;
}