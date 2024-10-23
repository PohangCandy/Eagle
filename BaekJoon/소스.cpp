//아이디어
// 그냥 주어진 depth까지 
// 방문여부와 상관없이 탐색하도록 만들어주면 되지 않을까?
//시간복잡도
// N^M이므로 최대 7 ^ 7 -> 10^7보다 작으므로 1초 이내
//자료구조
// 메모리
//	방문여부 배열을 사용하지 않는다.
//  int 자료형만 표시한다.
//  방문 노드 누적 최대 벡터 int * 7
// 자료형
//  최대 7

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> vec;

//dfs가 중단될 조건
// depth에 도달하면 멈춘다.
//파라미터
// 현재 높이를 저장할 int m
void dfs(int m)
{
	if (m == M)
	{
		for (auto& a : vec)
		{
			cout << a << " ";
		}
		cout << "\n";
	}
	else if (m > M)
	{
		cout << "out of depth";
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			vec.push_back(i);
			dfs(m + 1);
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
		dfs(1);
		vec.pop_back();
	}

	return 0;
}