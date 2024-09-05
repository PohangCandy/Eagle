// 두 수를 입력 받아서 최소공배수를 출력하자.
// 하나의 수의 배수를 구한 후, 다른 수로 나눠서 나머지가 0이면 공배수가 된다.
// 더 큰 수를 찾아서 해당 수의 배수를 작은 수로 나누는 작업이 더 효율적이다.

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int first, second;
		int common_mutiple;

		cin >> first >> second;
		if (first >= second)
		{
			int i = 1;
			while (1)
			{
				int first_copy = first * i;
				if (first_copy % second == 0)
				{
					common_mutiple = first_copy;
					break;
				}
				i++;
			}
			cout << common_mutiple << "\n";
		}
		else
		{
			int i = 1;
			while (1)
			{
				int second_copy = second * i;
				if (second_copy % first == 0)
				{
					common_mutiple = second_copy;
					break;
				}
				i++;
			}
			cout << common_mutiple << "\n";
		}

	}

	return 0;
}