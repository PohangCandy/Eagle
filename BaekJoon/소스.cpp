//to_string을 사용해서 좀 더 간단한 코드로 작성해본다.
#include <iostream>
#include <string>
using namespace std;

int remocon[10] = {0};

bool check(int n)
{
	//수를 string으로 변환해서 
	//자릿수에 해당하는 수의 고장여부를 
	//인덱스를 통해 간단하게 체크한다.
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++)
	{
		//고장난 버튼인 경우 
		if (remocon[s[i] - '0'] == 1)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int broken;
	cin >> broken;
	for (int i = 0; i < broken; i++)
	{
		int input;
		cin >> input;
		remocon[input] = 1;
	}
	//먼저 그냥 위아래 버튼을 움직이는 경우를 구한다.
	int result = abs(N - 100);

	// 최대로 입력될 수 있는 경우가 500000이므로
	// 리모컨이 고장날 경우를 고려해 최대 999999를 입력받을 수 있다.
	// i 가 500000 이고  키보드가 9만 멀쩡할 경우
	for (int i = 0; i <= 999999; i++)
	{
		//i에 해당하는 값의 키보다가 고장나지 않았는지 체크한다.
		if (!check(i))
		{
			continue;
		}

		//사용된 버튼이 모두 고장나지 않았을 경우
		//해당 채널에서의 거리를 구한다.
		string s = to_string(i);
		int count = abs(N - i) + s.length();
		result = min(result,count);
	}

	cout << result;

	return 0;
}