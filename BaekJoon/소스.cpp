#include <iostream>
using namespace std;

//간단한 문제 같은데 퍽킹 시간초과가 발생한다.
//팩토리얼 공식이 따로 있는건가?
//N! = 1 * 2 * 3 * ... * N
//2와 5의 배수 쌍이 얼마나 있는지 찾아볼까?

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long N;
	cin >> N;
	long long pac = 1;
	long long count_two = 0;
	long long count_five = 0;
	for (long long i = 1; i <= N; i++)
	{
		int j = i;
		while (j % 2 == 0)
		{
			count_two++;
			j /= 2;
		}

		while(j % 5 == 0)
		{
			count_five++;
			j /= 5;
		}
	}

	//둘 중에 더 적은 값이 정답이 된다.
	if (count_two >= count_five)
	{
		cout << count_five;
	}
	else
	{
		cout << count_two;
	}

	return 0;
}