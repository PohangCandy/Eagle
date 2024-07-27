#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	// 소인수분해 
	// 2부터 나머지가 0이 되는 수를 찾고
	// 제일 처음에 나눠지는 값으로 나눈 후
	// 다시 2부터 나눠지는 수를 찾는다.
	// 해당 작업을 반복한 후,
	// 몫이 1이되면 해당 작업을 멈춘다.

	while (1)
	{
		for (int i = 2; i <= N; i++)
		{
			if (N % i == 0)
			{
				cout << i << "\n";
				N = N / i;
				break;
			}
		}
		if (N == 1)
			break;
	}



	return 0;
}