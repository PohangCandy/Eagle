//아이디어
// dfs를 돌면서, 기준이 되는 노드보다 
// 크거나같은 노드들을 모두 출력해준다.
// 
// 걍 재귀함수 써도 쉽게 풀릴거 같은데?
// i부터 N까지 출력하도록 하면 되지 않을까?
// 
//시간복잡도
// N! = 8! - > 10^8이하이므로 1초 이내
// 
//자료구조
// 메모리
//  재방문과는 상관없이 
// 자료형
#include <iostream>
#include <vector>
using namespace std;

//RecursiveFunction, 재귀함수
//재귀를 끝낼 조건
// int n이 N이되면 stop
vector<int> vec;
int N, M;

void RF(int n)
{
	if (n == N)
	{
		vec.push_back(n);
		for (auto& a : vec)
		{
			cout << a << " ";
		}
		cout << "\n";
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);



	return 0;
}