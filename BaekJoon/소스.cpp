// 쇠막대기 레이저로 자르기
// ()가 레이저 ( 가 막대의 시작점이다.
// )가 나오기 전까지 얼마나 많은 ()쌍이 있는지 찾으면 된다.
// 막대의 개수는 레이저의 개수 + 1이 된다.

// 레이저가 나오면 현재 있는 막대기들은 모두 짤린다.
// )가 나오면 가장 최근에 있는( 값을 pop한다
// pop한 후 남아있는 사이즈가 남아있는 막대의 개수이므로
// size만큼을 더해준다.
// 이전에 들어왔던 값이 (가 아니라 
// )라는 것을 판별해줄 bool값을 넣어서
// true라면 그 다음에 오는 )는 막대의 끝 부분이다.
// 이 경우 size를 더하지 않고 pop만 실행해준다.

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;
	stack<char> stk;

	int num = 0;
	bool laser = false;

	for (auto a : input)
	{
		//막대가 추가된 경우 개수를 증가시켜준다.
		if (a == '(')
		{
			stk.push(a);
			num++;
			//다음에 )가 오면 laser가 된다.
			laser = true;
		}
		else if (a == ')')
		{
			// 레이저인 경우와 막대의 끝인 경우 두가지가 있다.
			// 바로 직전에 ( 가 있었다면 레이저가 된다.
			if (laser)
			{
				//먼저 직전에 막대로 인식했던 (를 빼준다.
				num--;
				stk.pop();
				//현재 막대기 개수만큼 더한다.
				num += stk.size();
				//곧 이어 나오는 )는 막대 끝을 의미한다.
				laser = false;
			}
			else
			{
				//막대 끝이라면 막대 하나를 스택에서 빼준다.
				stk.pop();
				//이후에 )가 와도 역시 막대끝이다.
				//laser = false;로 유지한다.
			}
		}
	}

	cout << num;

	return 0;
}