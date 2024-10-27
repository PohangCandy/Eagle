//아이디어
// 방문하지 않은 노드를 탐색하므로 dfs로 풀 수 있을 듯 하다.
// 노드를 탐색하면서 더한 비용의 총합 중 가장 작은 값을 결과로 출력한다.
// 다시 돌아와야 하네?
// 마지막에 스타트 지점으로 돌아오기 위해서 가장 처음 시작하는 값을 저장해두어야한다.
//
// 반례가 존재한다.
//4
//0 0 1 1
//1 0 1 1
//1 0 0 1
//1 1 1 1
// 이렇게 될 경우 모든 노드를 탐방하지 않고 마음대로 값이 나온다.
// 
//시간복잡도
// 방문하지 않은 노드를 탐색하는 총 경우의 수 N!
// 최대 10!, 10^8보단 작다.
// 
//메모리
// 방문한 노드 배열 int * 11
// 가격 배열 int * 11 * 11
// 
//자료형
// 최대 10^6 * 10 = 10^7이므로 int로 충분

#include <iostream>
#include <vector>
using namespace std;

int N;

vector<int> vec;

int visited[11] = { 0 };
int price[11][11] = { 0 };

int result = 10000001;

//도시를 순차적으로 방문하면서 최솟값을 찾자.
//dfs는 특정 높이에 다다르면 그만둔다.
//dfs가 출발하는 지점에 대한 정보가 필요하다.
void dfs(int s,int before, int h)
{
	if (h == N)
	{
		//처음 노드로 돌아 갈 수 있는지 여부를 판단한다.
		if (price[before][s] != 0)
		{
			int total = 0;
			for (auto& a : vec)
			{
				total += a;
			}

			//마지막 노드에서 처음 노드로 돌아가는 가격을 더한다.
			total += price[before][s];

			result = min(result, total);
		}
	}
	else if (h > N)
	{
		cout << "out of height";
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (visited[i]) continue;
			if (price[before][i] == 0) continue;
			visited[i] = 1;
			//이전 노드인 before에서 i번째 노드로 방문하는 가격을 더한다.
			vec.push_back(price[before][i]);
			dfs(s,i, h + 1);
			vec.pop_back();
			visited[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int input;
			cin >> input;
			price[i][j] = input;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		visited[i] = 1;
		dfs(i, i, 1);
		visited[i] = 0;
	}

	cout << result;

	return 0;
}