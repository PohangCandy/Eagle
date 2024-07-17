#include <iostream>
using namespace std;


//char input[5][15]; //5단어,최대 길이 15

int main()
{

	char input[5][15] = {0}; //5단어,최대 길이 15, 전역 변수의 경우 따로 0으로 초기화 해주어야 한다.
	//5단어를 받는다.
	for (int i = 0; i < 5; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (input[j][i] != NULL)
			{
				cout << input[j][i];
			}
		}
	}


	return 0;
}

