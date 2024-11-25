//아이디어
// 사이클이 있으려면 적어도 두개의 인접합 노드의 색상이
// 같은 색상이어야 한다.
// 좌상, 좌하, 우상, 우하 네 종류의 인접한 노드가 있을 수 있다.
// 인접한 노드를 각각 A,B,C,D라고 할 때
// 상,하,좌,우 dfs탐색을 하고, A에서 출발해서 B || C || D에 도착할 수 있다면, 
// 사이클이 존재한다.

#include <iostream>
using namespace std;

char Tile[50][50];
int visited[50][50];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int N, M;
int sx, sy;

void dfs(int y, int x)
{
	//사이클이 이루어지는지 확인하는 작업
	for (int i = 0; i < 4; i++)
	{

	}

	for (int i = 0; i < 4; i++)
	{
		if (y + dy[i] < 0 || y + dy[i] >= N || x + dx[i] < 0 || x + dx[i] >= M) continue;
		if (Tile[y + dy[i]][x + dx[i]] != Tile[y][x]) continue;
		if (visited[y + dy[i]][x + dx[i]]) continue;

		dfs(y + dy[i], x + dx[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			Tile[i][j] = s[i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			sy = i;
			sx = j;
			dfs(i, j);
		}
	}


	return 0;
}
