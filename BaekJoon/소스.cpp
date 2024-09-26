#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//소문자,대문자,숫자,공백의 개수를 담을 공간
	int result[5];

	string input;
	//입력이 eof가 아닐경우 계속 진행
	while (getline(cin, input))
	{
		//모든 개수 0으로 초기화
		for (int i = 0; i < 4; i++)
		{
			result[i] = 0;
		}

		for (auto& a : input)
		{
			if (a == ' ')
			{
				result[3]++;
			}
			else if (a >= 'A' && a <= 'Z')
			{
				result[1]++;
			}
			else if (a >= 'a' && a <= 'z')
			{
				result[0]++;
			}
			else
			{
				result[2]++;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			cout << result[i];
			if (i != 3) cout << " ";
		}
		cout << "\n";
	}


	return 0;
}