// 시간제한이 있으므로 이중 포문으로 구할 수 없다.
// 입력 받은 값이 이전에 입력받은 값보다 더 큰 경우 해당 값이 오큰수가 된다.
// 오큰수를 찾지 못한 수의 인덱스 번호를 스택에 저장해두고
// 다음 입력값과 비교해서 오큰수를 찾았다면
// pop으로 스택에 있는 인덱스 값을 빼준다.
// 스택이 빌때까지 값을 비교하다
// 입력 값이 스택에 있는 인덱스 값보다 작다면 break하고
// stack에 push 한다.
// 모든 입력이 끝난 후에도 스택에 남아있는 값들은
// 오큰수를 -1로 배정해준다.

#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
int res[1000001];
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
		// 스택이 빌 때까지,
		// 지금 입력받은 값과 
		// 스택에 있는 값을 비교한다.
		while (!stk.empty())
		{
			//만약 입력값이 스택의 top이 가르키는 인덱스 값보다 크다면
			//입력값은 해당 수의 오큰 수가 된다.
			if (input > arr[stk.top()])
			{
				res[stk.top()] = input;
				stk.pop();
			}
			//작다면 입력값의 인덱스를 스택에 push한다.
			else
			{
				break;
			}
		}
		stk.push(i);
	}

	//모든 입력을 마친 후에 스택에 남아있는 값들은 -1을 대입
	while (!stk.empty())
	{
		res[stk.top()] = -1;
		stk.pop();
	}

	for (int i = 0; i < N; i++)
	{
		cout << res[i] << " ";
	}

	return 0;
}