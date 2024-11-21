//아이디어
// dfs는 연결된 노드를 조사하고 
// 순서대로 탐색하게 하면 된다.
// bfs는 연결된 노드를 큐에 넣고,
// 큐에 있는 노드를 탐색하게 한다.

//벡터로 입력을 받았더니,정렬이 되지 않으므로
//벡터 안 내용을 정렬해준다.

//모든 노드가 탐색 가능하다는 전제가 없으므로
// 길이가 최대가 되는 탐색이 결과가 되게 해준다.

//시간초과가 발생한다.
// 최대 높이를 찾을때까지 탐색을 하도록 만들어 주어서 그런듯하다.
// dfs, bfs를 사용할때 
// 끊어진 트리가 없다는 점을 가정하여
// 간선의 개수로 최대 방문 가능한 정점의 개수를
// 최대 높이로 정해본다.

//N은 최대 1000
//M은 최대 10000

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M, V;
int maxHeight = 0;

vector<int> node[1001];

queue<int> que_bfs;

int visited[1001];

void dfs(int s)
{
	visited[s] = 1;
	cout << s << " ";

	//노드가 연결하고 있는 모든 간선을 조사한다.
	for (int i = 0; i < node[s].size(); i++)
	{
		if (!visited[node[s][i]])
		dfs(node[s][i]);
	}
}

void bfs(int s)
{
	visited[s] = 1;
	que_bfs.push(s);

	//큐가 비어있지 않다면
	while (!que_bfs.empty())
	{
		// 큐의 프론트에 있는 값을 출력하고,
		// 프론트와 연결된 노드를 큐에 집어넣는다.
		cout << que_bfs.front() << " ";
		int x = que_bfs.front();
		que_bfs.pop();

		//큐의 프론트에 있던 정점과 연결된 정점을 다시 큐에 담아준다.
		for (int i = 0; i < node[x].size(); i++)
		{
			//노드가 갈 수 있는 노드를 모두 큐에 담는다.
			if (!visited[node[x][i]])
			{
				visited[node[x][i]] = 1;
				que_bfs.push(node[x][i]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(node[i].begin(), node[i].end());
	}

	dfs(V);

	memset(visited, 0, sizeof(visited));
	cout << "\n";

	bfs(V);

	return 0;
}
