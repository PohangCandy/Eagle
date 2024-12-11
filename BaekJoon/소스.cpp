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
// 노드를 클래스로 나타내고
// 노드에 저장할 정보를 담아본다.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


//if N = 4 , M = 4
//Tile[0] -> 0,0
//Tile[1] -> 0,1
//Tile[2] -> 0,2
//Tile[3] -> 0,3
//Tile[k] -> x = k/4 , y = k%4
//k = x * 4 + y


class Node {
	//좌표
	int x;
	int y;
	//벽 여부
	bool wall;
	//방문여부
	int visited;
	//탐색 높이
	int height;
public:
	Node(int _x, int _y, bool _w, int _v = 0, int _h = 0) : x(_x), y(_y), wall(_w), visited(_v), height(_h) {}

	bool operator==(const Node n)const {
		return ((this->x == n.x) && (this->y == n.y));
	}

	//여기 연산자 오버로딩에서 부호 방향을 틀렸었다.
	//이것 때문에 한참 찾음
	bool operator<(const Node n) const
	{
		return this->height > n.height;
	}

	int getheight()
	{
		return height;
	}

	void setheight(int h)
	{
		height = h;
	}

	bool ans(int _x, int _y)
	{
		return ((this->x == _x) && (this->y == _y));
	}

	int getxpos()
	{
		return x;
	}

	int getypos()
	{
		return y;
	}

	bool isvisited()
	{
		return visited;
	}

	void setvisited()
	{
		visited = 1;
	}

	bool isWall()
	{
		return wall;
	}
};


int N, M;
int ans = 10000;

vector<Node> Tile;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs()
{
	//우선순위 큐를 이용해 높이가 낮은 노드를 먼저 탐색하게 한다.
	priority_queue<Node, vector<Node>> pq;
	//처음 0,0노드에서 시작
	Tile[0].setvisited();
	pq.push(Tile[0]);
	//cout << "(0,0)-> ";

	while (!pq.empty())
	{
		Node n = pq.top();
		//목적지에 다다른 노드의 높이를 출력한다.
		if (n.ans(N - 1, M - 1))
		{
			ans = min(ans, n.getheight());
			pq.pop();
			//cout << "(" << n.getxpos() << "," << n.getypos() << ")" << "-> ";
			//우선 순위 큐가 항상 높이가 낮은 경로를 우선 탐색해부므로
			//가장 처음 목적지에 다다랐을때가 최단 경로가 될 것이다.
			break;
		}
		pq.pop();

		//cout << "(" << n.getxpos() << "," << n.getypos() << ")" << "-> ";

		//상하좌우로 이동
		for (int i = 0; i < 4; i++)
		{
			int x = n.getxpos();
			int y = n.getypos();

			//x,y 죄표로 Tile에 저장된 값 인덱스 찾기
			if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M) continue;

			int curh = Tile[x + y * N].getheight();
			int nexth = Tile[x + dx[i] + (y + dy[i]) * N].getheight();
			bool nextIswall = Tile[x + dx[i] + (y + dy[i]) * N].isWall();
			bool nextIsvisited = Tile[x + dx[i] + (y + dy[i]) * N].isvisited();
			bool next_Got_higher_height = (nextIswall && (nexth > curh + 1)) || (!nextIswall && (nexth > curh));

			//이미 방문한 타일을 재방문한 경우
			if (nextIsvisited && (!next_Got_higher_height))
			{
				//높이가 더 작은 경우가 존재한다면 갱신한다.
				//그 외에는 재방문하지 않는다.
				continue;
			}

			//방문하지 않은 타일을 방문했을 경우,
			// 방문 표시를 업데이트 해준다.
			if (!nextIsvisited)
			{
				Tile[x + dx[i] + (y + dy[i]) * N].setvisited();
			}

			//벽인 경우, 높이를 증가시킨다.
			//증가시킨 높이가 정답보다 큰 경우, continue
			if (nextIswall)
			{
				if (curh + 1 > ans) continue;
				Tile[x + dx[i] + (y + dy[i]) * N].setheight(curh + 1);
			}
			//벽이 아니라면 높이는 유지된다.
			else
			{
				Tile[x + dx[i] + (y + dy[i]) * N].setheight(curh);
			}

			//우선순위 큐에 탐색한 노드를 올린다. 
			pq.push(Tile[x + dx[i] + (y + dy[i]) * N]);
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	//4 2
	//0001
	//1000
	// 0~7까지 Tile[7]까지 만들어진다.

	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			//node(x,y,w)
			Node node(j, i, s[j] - '0');
			Tile.push_back(node);
		}
	}

	bfs();

	//cout << "\n";
	cout << ans;

	return 0;
}
