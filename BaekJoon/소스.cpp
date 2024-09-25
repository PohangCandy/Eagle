// 피연산자를 스택에 넣고, 
// 연산자를 만난 경우
// 스택에 있는 두 값을 꺼내서 연산해준다.
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//알파벳의 숫자 값을 집어넣을 배열을 만들어준다.
	int alpha[27];

	int N;
	cin >> N;
	string str;
	cin >> str;

	stack<int> stk;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		//알파벳에 저장될 수를 배열에 저장
		alpha[i] = input;
	}

	for (int i = 0; i < str.length(); i++)
	{
		// 앞에서부터 순서대로 검사하면서
		// 피연산자를 스택에 넣는다.
		// 연산자를 만나면 스택에 있는 두 개의 값을 꺼내서 연산하자.

		
	}

	return 0;
}