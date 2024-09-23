// 단어 뒤집기
// <>가 있는 친구들은 그대로 나오고
// 나머지는 반대로 뒤집혀 나오므로
// deq을 사용해서
// <가 감지되면
// >가 나올때까지 받은 그대로 pop한다.
// 공백문자의 경우,
// deq가 비워질때까지 pop_back 한다.
// 일반문자의 경우 push_front 한다.

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	deque<char> deq;

	string input;
	getline(cin, input);
	// 공백문자를 기준으로 단어를 뒤집을 것이므로
	// 임의로 공백문자를 추가한다.
	input += " ";
	bool p_f = false;

	for (auto& a : input)
	{
		if (a == ' ')
		{
			while (!deq.empty())
			{
				cout << deq.back();
				deq.pop_back();
			}
			cout << " ";
		}
		else if (a == '<')
		{
			p_f = true;
			deq.push_front(a);
		}
		else if (a == '>')
		{
			if (p_f)
			{
				deq.push_front(a);
				p_f = false;
				while (!deq.empty())
				{
					cout << deq.back();
					deq.pop_back();
				}
			}
			else
			{
				deq.push_back(a);
			}
		}
		else
		{
			if (p_f)
			{
				deq.push_front(a);
			}
			else
			{
				deq.push_back(a);
			}
		}
	}

	return 0;
}