#include <iostream>
using namespace std;

int main()
{
	// 상근이가 최대한 적은 수의 봉지를 배달하도록 도와준다.
	// 5kg이 많을 수록 더 적은 수의 봉지를 배달할 수 있다.
	// 그렇다고 9kg짜리를 5kg으로 나눌 수 없다. 4kg을 배달할 수 없기 때문이다.
	// 5로 나누어 떨어지는 수는 5kg으로 배달 할 수 있다.
	// 주문한 키로 수에서 5로 최대한 뺄 수 있는 만큼 뺀다.
	// 정확하게 떨어지지 않으면 5키로를 뺀 횟수를 줄이고 3키로를 늘린다.
	// 3키로를 최대로 늘려도 정확한 수를 맞툴 수 없다면 -1을 출력해준다.

	int N;
	cin >> N;

	int numofFive = N / 5;
	int numofThree = N / 3;

	int last = N;
	int time = 0;

	// 입력한 숫자를 5로 나눌 수 있는 최대 횟수는 
	// 입력 숫자를 5로 나눈 몫과 같다.
	// 3도 마찬가지 
	for (int i = 0; i < numofThree; i++)
	{
		for (int j = numofFive; j > 0; j--)
		{
			if (last % 5 != 0)
			{
				break;
			}
			else if(last % 3 != 0)
			{

			}

			last -= 5;
			time++;
		}

		last -= 3;
		time++;
	}


	return 0;
}