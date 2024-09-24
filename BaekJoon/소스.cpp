// count 함수를 사용해서 입력받은 요소를 배열에 저장해둔 후
// 가장 최근에 들어온 값이 자신의 개수보다 크면 해당 값을 result로 갖도록해준다.

#include <iostream>
#include <stack>
using namespace std;

int arr[1000001];
//개수 저장
int num[1000001] {0};
//자신보다 많은 수 저장
int res[1000001];

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
		//인덱스 번호에 개수를 저장
		num[input] += 1;
	}

	stack<int> stk;

	for (int i = 0; i < N; i++)
	{
		// 인덱스 번호를 스택에 push하면서 
		// num[stk.top()]와 num[arr[i]]를 비교해서
		// 스택의 탑에 있는 값의 개수가 더 작다면
		// res[stk.top()] = arr[i]이 된다.
		//스택이 빌때까지 해당 작업을 반복한다.
		while (!stk.empty())
		{
			// 스택의 인덱스 번호는 0부터 시작하므로
			// num의 인덱스와 맞추기 위해 +1을 해준다.
			if (num[arr[i]] > num[arr[stk.top()]])
			{
				res[stk.top()] = arr[i];
				stk.pop();
			}
			else
			{
				break;
			}
		}

		stk.push(i);
	}

	//스택에 남아있는 친구들에겐 -1을 준다.
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