//아이디어
// dfs는 연결된 노드를 조사하고 
// 순서대로 탐색하게 하면 된다.
// bfs는 연결된 노드를 큐에 넣고,
// 큐에 있는 노드를 탐색하게 한다.

//벡터로 입력을 받았더니,정렬이 되지 않으므로
//벡터안 내용을 정렬해준다.

//모든 노드가 탐색 가능하다는 전제가 없으므로
// 길이가 최대가 되는 탐색이 결과가 되게 해준다.


#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int N, M, V;
int maxHeight = 0;

vector<int> node[1001];

vector<int> result;

vector<int> vec_dfs;
bool find_dfs = false;

vector<int> vec_bfs;
bool find_bfs = false;

queue<int> que_bfs;

int visited[1001];

void dfs(int h, int s)
{
	if (find_dfs) return;

	if (h > maxHeight)
	{
		maxHeight = h;
		result = vec_dfs;
		if (h == M + 1) find_dfs = true;
	}

	//노드가 연결하고 있는 모든 간선을 조사한다.
	for (int i = 0; i < node[s].size(); i++)
	{
		if (visited[node[s][i]]) continue;
		visited[node[s][i]] = 1;
		vec_dfs.push_back(node[s][i]);
		dfs(h + 1, node[s][i]);
		vec_dfs.pop_back();
		visited[node[s][i]] = 0;
	}

}

void bfs(int c, int s)
{
	if (find_bfs) return;

	if (c > maxHeight)
	{
		result = vec_bfs;
		if (c == M + 1) find_bfs = true;
	}

	for (int i = 0; i < node[s].size(); i++)
	{
		//노드가 갈 수 있는 노드를 모두 큐에 담는다.
		if (visited[node[s][i]]) continue;
		que_bfs.push(node[s][i]);
	}
	//큐 앞에 있는 친구를 뽑아서 다시 탐색한다.

	if (!que_bfs.empty())
	{
		int qfront = que_bfs.front();
		que_bfs.pop();

		if (visited[qfront]) return;
		vec_bfs.push_back(qfront);
		visited[qfront] = 1;
		bfs(c + 1, qfront);
		visited[qfront] = 0;
		vec_bfs.pop_back();
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

	for (int i = 0; i < N; i++)
	{
		sort(node[i].begin(), node[i].end());
	}

	visited[V] = 1;
	vec_dfs.push_back(V);
	dfs(1, V);
	vec_dfs.pop_back();
	visited[V] = 0;

	for (auto& a : result)
	{
		cout << a << " ";
	}
	cout << "\n";
	result.clear();
	maxHeight = 0;

	visited[V] = 1;
	vec_bfs.push_back(V);
	bfs(1, V);
	vec_bfs.pop_back();
	visited[V] = 0;

	for (auto& a : result)
	{
		cout << a << " ";
	}
	cout << "\n";

	return 0;
}
