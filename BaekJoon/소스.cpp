//아이디어
//개쩌는 규칙을 찾아냈다.
// 그냥 마지막 노드 i부터 방문을 해제한다.
//  방문하지 않은 노드 중에
//  해제한 노드보다 더 큰 값이 있는지 체크한다.
// 있으면 해당 노드를 벡터에 담고, 방문 체크한 후
//	방문하지 않은 노드를 작은 순서로 담는다.
// 없으면 i-1 노드의 방문을 해제하고 
//  방문하지 않은 노드 중에 
//  해제한 노드보다 더 큰 값이 있는지 체크한다.
// 
//시간복잡도
// 10^4^2 = 10^8
// 
//메모리
// 입력된 수열 저장할 벡터 int * 10001
//자료형
// int, 최대 10000

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> vec;

int visited[10001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= 10000; i++)
	{
		//모든 배열의 수를 방문한 상태로 초기화 해둔다.
		visited[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}

	while (!vec.empty())
	{
		//벡터 뒤부터 해제
		int back = vec.back();
		visited[back] = 0;
		vec.pop_back();

		//back보다 큰 수 중 방문하지 않은 노드 찾기
		bool find = false;
		for (int j = back + 1; j <= N; j++)
		{
			if (j <= 10000 && 0 <= j)
			{
				if (visited[j] == 0)
				{
					find = true;
					visited[j] = 1;
					vec.push_back(j);
					break;
				}
			}
		}

		if (find)
		{
			for (int i = 1; i <= N; i++)
			{
				if (!visited[i])
				{
					visited[i] = 1;
					vec.push_back(i);
				}
			}
			break;
		}

		//큰 수보다 작은 값 중 가장 
	}

	if (vec.empty())
	{
		cout << -1;
	}
	else
	{
		for (auto& a : vec)
		{
			cout << a << " ";
		}
	}


	return 0;
}
