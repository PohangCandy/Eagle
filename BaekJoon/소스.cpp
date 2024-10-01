// n진법 연산은 주어진 input을 n으로 나눈 나머지를 출력한 결과로 나타낸다.
// -n진법의 경우 나머지가 -가 나올 수 있다.
// -로 나온 나머지를 양수로 바꾸려면 어떻게 해야할까?
// -2진법의 경우, 
// -5는 -2 * 3 + 1 또는 -2 * 2 - 1 두 가지 표현될 수 있다.
// 컴파일러는 이럴때 어떻게 출력할까?
// c++ 컴파일러는 2를 출력한다.
// 5는 -2 * -2 + 1 또는 -2 * -3 -1 두 가지로 표현될 수 있다.
// c++ 컴파일러는 -2를 출력한다.
// 나머지를 양수로 표현하기 위해서
// -5는 -6 + 1으로 5는 4 + 1로 표현되어야 한다.
// 그러므로 홀수인 경우 -1을 해서 짝수로 만든 후 연산하고 
// 나머지 값으로 1을 출력해준다.
// 

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//결과를 저장해줄 벡터
	stack<int> res;
	int N;
	cin >> N;

	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	while (N != 0)
	{
		if ((N % -2) == 0)
		{
			res.push(0);
			N /= -2;
		}
		else
		{
			res.push(1);
			N -= 1;
			N /= -2;
		}
	}

	while (!res.empty())
	{
		cout << res.top();
		res.pop();
	}

	return 0;
}