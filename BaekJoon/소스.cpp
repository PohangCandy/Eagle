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
#include <deque>
//중복된 거리를 제거하고 남은 간격의 최대공약수를 구하기위해 집합을 이용한다.
#include <set>
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
	vector <int> vec;
	vector <int> distance;
	deque <int> gap;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	//정렬한 가로수 간격을 벡터에 따로 저장한다.
	auto it_v = vec.begin();
	while (it_v + 1 != vec.end())
	{
		distance.push_back(*(it_v + 1) - (*it_v));
		gap.push_back(*(it_v + 1) - (*it_v));
		it_v++;
	}

	// 덱의 첫번째와 두번째 요소를 꺼내서
	// 최대 공약수를 구한 후
	// 첫번째, 두번째 요소는 삭제한다.
	sort(gap.begin(), gap.end());

	while (gap.size() >= 2)
	{
		//int gcd = GCD(gap[0], gap[1]);
		int gcd = GCD(*gap.begin(), *(gap.begin()+1));
		gap.push_back(gcd);
		gap.pop_front();
		gap.pop_front();
	}

	int gcd = gap[0];
	
	//간격의 최대공약수 하나를 추출했다.
	//이제 가장 작은 가로수부터
	//가장 먼 가로수까지 몇개의 가로수가 들어갈지 구한 후
	//지금 있는 가로수의 개수와의 차이를 구한다.
	//(최대 거리 - 최소 거리 ) / 간격  + 1 = 총 개수
	int all_branch_num = (((*(vec.end()-1)) - (*vec.begin())) / gcd) + 1;

	cout << all_branch_num - vec.size();

	return 0;
}