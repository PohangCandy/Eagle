#include <iostream>
#include <map>
using namespace std;

// 포켓몬의 이름과 번호를 연결한다
// key로 이름을 받고 value에 번호를 입력한다.
// 근데 이러면 value로 key값을 찾을 수 있나?? 
// pair를 통해 키 값을 두 쌍으로 만들면 어떨까?
// 수를 통해서든, 단어를 통해서든 value값을 추출해본다.

int main()
{
	ios_base::sync_with_stdio(false);
	map<string, int> dic;


	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		dic[input] = i + 1;
	}

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		//이름이 주어질 경우 번호를 출력한다.
		if(dic.find(input) != dic.end())
			cout << dic[input] <<"\n";
		//번호가 주어질 경우 이름을 어떻게 출력할까?
		else {
			int size = input.size();
			int input_int = 0;
			for (auto& b : input)
			{
				int size_c = size;
				int i;
				i = (b - '0');
				while(size_c != 1)
				{
					i *= 10;
					size_c--;
				}
				input_int += i;
				size--;
			}
			for (auto& a : dic)
			{

			if (a.second == input_int)
			{
				cout << a.first << "\n";
			}
			}
		}
	}

	return 0;
}