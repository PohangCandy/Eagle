//아이디어
// 방문하지 않은 단지를 방문하면서 dfs를 한다.
// 방문한 단지의 최대 높이를 벡터 배열에 저장한다.


#include <iostream>
#include <vector>
using namespace std;


int Tile[25][25] = { 0 };
int visited[25][25] = { 0 };
//상하좌우
int x[4] = { 0,0,-1,1 };
int y[4] = { 1,-1,0,0 };

void dfs(int w, int h)
{
	for (int i = 0; i < 4; i++)
	{
		if (visited[w + x[i]][h + y[i]]) continue;
		visited[w + x[i]][h + y[i]] = 1;
		dfs(w + x[i], h + y[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Tile[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[Tile[i][j]]) continue;
			dfs(i , j);
		}
	}


	return 0;
}
