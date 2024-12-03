//아이디어
//	문제의 핵심은 벽을 최소한으로 뚫는 것
//	목적지까지 가는 모든 경로를 탐색하고
//	벽이 최소한으로 뚫리는 길을 
//	알아봐야 할 거 같은데??

// (1,1)에서 (N,M)으로 움직이려면
// 상,좌 보단 하,우로 움직이고
// 벽이 있는 공간보단 없는 공간으로 먼저 탐색을 해야한다.
// 근데 그럼 다른데 최단 거리가 존재할 수 있지 않을까?

//그럼 이건 어떨까?
// 빈방을 먼저 탐색한 후
// 하, 우를 우선으로 탐색하고,
// 목적지에 도착했을때 최소 높이를 저장해둔다.
// 큐에 들어있는 모든 노드들이
// 최소 높이를 초과하지 않을때 탐사를 계속해준다.

// 벽을 뚫은 횟수가 
// 적은 탐색 경로를 우선으로 탐색한다.

#include <iostream>
#include <deque>
using namespace std;

int N, M;

int Tile[101][101];
int visited[101][101] = {0};
int h[101][101] = {0};

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs()
{
	deque<pair<int,int>> d;
	d.push_back({ 1, 1 });

	// 빈 방 먼저,
	// 하,우 방향 먼저 부시기
	while (!d.empty())
	{
		int fy = d.front().first;
		int fx = d.front().second;

		if (fy == M && fx == N)
		{
			cout << h[fy][fx];
			break;
		}

		//빈 방을 모두 탐색하고,
		//더 이상 탐색할 빈방이 없으면 
		//벽을 하나씩 뚫어본다.
		for (int i = 0; i < 4; i++)
		{
			if (fy + dy[i] < 0 || fy + dy[i] >= M || fx + dx[i] < 0 || fx + dx[i] > N) continue;
			if (visited[fy + dy[i]][fx + dx[i]]) continue;
			visited[fy + dy[i]][fx + dx[i]] = 1;
			if (!Tile[fy + dy[i]][fx + dx[i]]) d.push_front(make_pair(fy + dy[i], fx + dx[i]));
			//벽을 뚫어야 하는 경우
			else
			{
				//높이를 어떻게 지정해줘야할까..
				h[fy + dy[i]][fx + dx[i]] = h[fy][fx] + 1;
				Tile[fy + dy[i]][fx + dx[i]] = 0;
				d.push_back(make_pair(fy + dy[i], fx + dx[i]));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			Tile[i][j] = s[j] - '0';
		}
	}

	bfs();
	
	return 0;
}


