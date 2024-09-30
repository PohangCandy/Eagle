// 주어진 수의 길이가 1,000,000이란 의미는
// 2^1,000,000까지 표현할 수 있다는 말과 같다.
// 이 값은 (2^10)^100000이므로 대략 10^300000이 된다.
// longlong이나 int형으로 표현할 수 없는 범위이므로
// string을 사용해서 입력을 받도록한다.

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;

	//8진법으로 바꾸려면 앞에서부터 세자리씩 끊어 바꾸면 된다.
	//input % 3을 확인하고, 0이 나오지 않을경우 앞에 0을 넣어서
	//나머지가 0이 되도록 만든다.
	while (input.size() % 3 != 0)
	{
		input = '0' + input;
	}
	//이제 3자리씩 8진법으로 읽어준다. 
	for (int i = 0; i < input.size(); i += 3)
	{
		cout << (input[i] - '0') * 4 + (input[i + 1] - '0') * 2 + (input[i + 2] - '0') * 1;
	}

	return 0;
}