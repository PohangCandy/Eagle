// 균일하게 가로수를 심기
// 주어진 거리 중에 가장 짧은 간격을 구한다.
// 3,2가 각 거리인 경우 간격의 거리가 2가 되면 안된다.
// 주어진 거리들의 최대공약수를 찾아야한다.
// 가장 작은 가로수 위치에서
// 최대공약수만큼 더한 값이 컨테이너에 없다면 추가하고 있다면 넘어간다.
// 해당 작업은 컨테이너 내의 가장 큰 값을 넘지 않을 때까지 반복한다.

#include <iostream>
//가로수를 추가하기위해 벡터를 쓰고
#include <vector>
//정렬하기위해 sort를 쓴다.
#include <algorithm>
using namespace std;

//최대공약수를 찾기 위한 함수
int GCD(int bigger, int smaller)
{
	if (bigger % smaller == 0)
	{
		return smaller;
	}
	else
	{
		return GCD(smaller, bigger % smaller);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> vec;
	vector<int> distance;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	auto it = vec.begin();
	while (it != vec.end())
	{
		distance.push_back(*(it + 1) - (*it));
	}


	return 0;
}