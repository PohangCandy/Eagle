//아이디어
// dfs를 돌면서, 기준이 되는 노드보다 
// 크거나같은 노드들을 모두 출력해준다.
// 
// 근데 걍 재귀함수 써도 쉽게 풀릴거 같은데?
// i부터 N까지 출력하도록 하면 되지 않을까?
// 
//시간복잡도
// N! = 8! - > 10^8이하이므로 1초 이내
// 
//자료구조
// 메모리
//  재방문과는 상관없이 진행하므로 int 변수만 사용
//  벡터에 들어가는 최대 메모리 int * 8 = 32byte
// 자료형
//	최대 8
#include <iostream>
#include <vector>
using namespace std;

//RecursiveFunction, 재귀함수
//재귀를 끝낼 조건
// int n이 N이되면 stop
vector<int> vec;
int N, M;

void RF(int s, int height)
{
	if (height == M)
	{
		for (auto& a : vec)
		{
			cout << a << " ";
		}
		cout << "\n";
	}
	else if (height > N)
	{
		cout << "out of height";
	}
	else
	{
		for (int i = s; i <= N; i++)
		{
			vec.push_back(i);
			RF(i, height + 1);
			vec.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		vec.push_back(i);
		RF(i, 1);
		vec.pop_back();
	}

	return 0;
}