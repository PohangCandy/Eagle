#include <iostream>
#include <vector>
using namespace std;
//수열에서 수를 하나 제거하는 경우의 수는 n
// 10^5
// 특정 수가 음수라면 
// 수를 하나씩 제거하면서 
// 최댓값을 구하면 되지 않을까?

// 어떻게 음수를 하나씩 제거한 버전을 만들까?
// 최대 10^5을 받으므로 이중포문을 쓰면 안된다.
// 음수가 하나씩 없는 부분수열을 만들 수 있을까?
// -> 양수들 사이에 있는 가장 큰 음수를 없애는게 관건이다.

//우선 양수가 나오면 반드시 다음에 음수가 나오게 만들어준다.
// 양수 다음에 오는 양수는 원래 위치에 더해준다.

vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// 10 -4 15 -35 33 -1
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		if (input > 0 && vec.back() > 0)
		{
			vec.back() += input;
		}
		else if (input < 0 && vec.back() < 0)
		{
			vec.back() += input;
		}
		else
		{
			vec.push_back(input);
		}
	}

	// 벡터를 순회하면서 3가지 정보를 가지고있는다.
	// 1. 지금까지 나온 가장 큰 음수에 대한 정보를 가지고 있는다.
	// 2. 현재 나올 수 있는 가장 큰 수열의 최댓값을 가지고있는다.
	// 3. 가장 큰 음수를 제외하고 음수를 더한 값을 가지고 있는다.
	// 만약 양수가 나왔는데 지금까지의 음수의 합들보다 크다면
	// 현재 나올 수 있는 가장 큰 수열이 3번 값으로 업데이트된다.
	// 


	return 0;
}