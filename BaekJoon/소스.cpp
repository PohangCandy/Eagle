// 모든 정점에서 dfs를 구하려고하니
// 시간복잡도가 n^2이되어 10^10이 되므로
// 시간초과가 발생했다.
// 
// 조사해본 결과 지름을 구하는 방법이 존재했다.
// 트리의 지름을 구하는 방법은 다음과 같다.
// 먼저 임의의 한 정점에서 가장 거리가 먼 정점 A를 찾는다.
// 정점 A에서 다시 가장 거리가 먼 정점 B를 찾는다.
// 이때 A,B가 이루는 거리가 트리의 지름이 된다.

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<pair<int, int>> tree[100001];
int visited[100001];
int ans = 0;
int firstMaxNode = 0;

void dfs(int s, int d)
{
	visited[s] = 1;
	if (d > ans) 
	{
		ans = d;
		firstMaxNode = s;
	}

	for (int i = 0; i < tree[s].size(); i++)
	{
		if (visited[tree[s][i].first]) continue;
		dfs(tree[s][i].first, tree[s][i].second + d);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int VertexNum;
	cin >> VertexNum;
	for (int i = 0; i < VertexNum; i++)
	{
		int start;
		cin >> start;
		
		while (1)
		{
			int end;
			cin >> end;
			if (end == -1) break;

			int distance;
			cin >> distance;

			tree[start].emplace_back(make_pair(end, distance));
		}
	}

	//임의의 정점은 1로 한다.
	dfs(1,0);
	//첫번째로 찾은 끈점에서 지름을 다시 구한다.
	memset(visited, 0, sizeof(visited));
	dfs(firstMaxNode, 0);

	cout << ans;
}
